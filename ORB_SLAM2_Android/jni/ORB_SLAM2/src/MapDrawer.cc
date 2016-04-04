/**
 * This file is part of ORB-SLAM2.
 *
 * Copyright (C) 2014-2016 Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
 * For more information see <https://github.com/raulmur/ORB_SLAM2>
 *
 * ORB-SLAM2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ORB-SLAM2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ORB-SLAM2. If not, see <http://www.gnu.org/licenses/>.
 */

#include "MapDrawer.h"
#include "MapPoint.h"
#include "KeyFrame.h"
#include<GLES/gl.h>
#include <GLES/glext.h>
#include <mutex>
#include <android/log.h>
#define LOG_TAG "ORB_SLAM_SYSTEM"

#define LOG(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)

namespace ORB_SLAM2 {

MapDrawer::MapDrawer(Map* pMap, const string &strSettingPath) :
		mpMap(pMap) {
	cv::FileStorage fSettings(strSettingPath, cv::FileStorage::READ);

	mKeyFrameSize = fSettings["Viewer.KeyFrameSize"];
	mKeyFrameLineWidth = fSettings["Viewer.KeyFrameLineWidth"];
	mGraphLineWidth = fSettings["Viewer.GraphLineWidth"];
	mPointSize = fSettings["Viewer.PointSize"];
	mCameraSize = fSettings["Viewer.CameraSize"];
	mCameraLineWidth = fSettings["Viewer.CameraLineWidth"];

}

void MapDrawer::DrawMapPoints() {
	const vector<MapPoint*> &vpMPs = mpMap->GetAllMapPoints();
	const vector<MapPoint*> &vpRefMPs = mpMap->GetReferenceMapPoints();

	set<MapPoint*> spRefMPs(vpRefMPs.begin(), vpRefMPs.end());

	if (vpMPs.empty())
		return;

	// 清除屏幕及深度缓存
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// 重置当前的模型观察矩阵
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	glScalef(2.0f,2.0f,2.0f);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glLineWidth(3.0f);
	glEnable (GL_COLOR_MATERIAL);
	glEnableClientState (GL_VERTEX_ARRAY);

	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	for (int i = 0, iend = vpMPs.size(); i < iend; i++) {
		if (vpMPs[i]->isBad() || spRefMPs.count(vpMPs[i]))
			continue;
		cv::Mat pos = vpMPs[i]->GetWorldPos();

		GLfloat vertexArray[3] = { pos.at<float>(0), pos.at<float>(1), pos.at<
				float>(2) };
		glVertexPointer(3, GL_FLOAT, 0, vertexArray);
		glDrawArrays(GL_POINTS, 0, 1);
	}
	glFlush();
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	for (set<MapPoint*>::iterator sit = spRefMPs.begin(), send = spRefMPs.end();
			sit != send; sit++) {
		if ((*sit)->isBad())
			continue;
		cv::Mat pos = (*sit)->GetWorldPos();
		GLfloat vertexArray[] = { pos.at<float>(0), pos.at<float>(1), pos.at<
				float>(2) };
		glVertexPointer(3, GL_FLOAT, 0, vertexArray);
		glDrawArrays(GL_POINTS, 0, 1);
	}
	glFlush();
}

void MapDrawer::DrawKeyFrames(const bool bDrawKF, const bool bDrawGraph) {
	const float &w = mKeyFrameSize;
	const float h = w * 0.75;
	const float z = w * 0.6;

	const vector<KeyFrame*> vpKFs = mpMap->GetAllKeyFrames();

	if (bDrawKF) {
		for (size_t i = 0; i < vpKFs.size(); i++) {
			KeyFrame* pKF = vpKFs[i];
			cv::Mat Twc = pKF->GetPoseInverse().t();
			glPushMatrix();
			glMultMatrixf(Twc.ptr < GLfloat > (0));
			glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
			GLfloat vertexArray[] = { 0, 0, 0, w, h, z, 0, 0, 0, w, -h, z, 0, 0,
					0, -w, -h, z, 0, 0, 0, -w, h, z, w, h, z, w, -h, z, -w, h,
					z, -w, -h, z, -w, h, z, w, h, z, -w, -h, z, w, -h, z };
			glVertexPointer(3, GL_FLOAT, 0, vertexArray);
			glDrawArrays(GL_LINES, 0, 16);
			glPopMatrix();
		}
	}

	if (bDrawGraph) {
		glLineWidth(mGraphLineWidth);
		glColor4f(0.0f, 1.0f, 0.0f, 0.6f);
		for (size_t i = 0; i < vpKFs.size(); i++) {
			// Covisibility Graph
			const vector<KeyFrame*> vCovKFs = vpKFs[i]->GetCovisiblesByWeight(
					100);
			cv::Mat Ow = vpKFs[i]->GetCameraCenter();
			if (!vCovKFs.empty()) {
				for (vector<KeyFrame*>::const_iterator vit = vCovKFs.begin(),
						vend = vCovKFs.end(); vit != vend; vit++) {
					if ((*vit)->mnId < vpKFs[i]->mnId)
						continue;
					cv::Mat Ow2 = (*vit)->GetCameraCenter();
					GLfloat vertexArray[] = { Ow.at<float>(0), Ow.at<float>(1),
							Ow.at<float>(2), Ow2.at<float>(0), Ow2.at<float>(1),
							Ow2.at<float>(2) };
					glVertexPointer(3, GL_FLOAT, 0, vertexArray);
					glDrawArrays(GL_LINES, 0, 2);
				}
			}

			// Spanning tree
			KeyFrame* pParent = vpKFs[i]->GetParent();
			if (pParent) {
				cv::Mat Owp = pParent->GetCameraCenter();
				GLfloat vertexArray[] = { Ow.at<float>(0), Ow.at<float>(1),
						Ow.at<float>(2), Owp.at<float>(0), Owp.at<float>(1),
						Owp.at<float>(2) };
				glVertexPointer(3, GL_FLOAT, 0, vertexArray);
				glDrawArrays(GL_LINES, 0, 2);
			}

			// Loops
			set<KeyFrame*> sLoopKFs = vpKFs[i]->GetLoopEdges();
			for (set<KeyFrame*>::iterator sit = sLoopKFs.begin(), send =
					sLoopKFs.end(); sit != send; sit++) {
				if ((*sit)->mnId < vpKFs[i]->mnId)
					continue;
				cv::Mat Owl = (*sit)->GetCameraCenter();
				GLfloat vertexArray[] = { Ow.at<float>(0), Ow.at<float>(1),
						Ow.at<float>(2), Owl.at<float>(0), Owl.at<float>(1),
						Owl.at<float>(2) };
				glVertexPointer(3, GL_FLOAT, 0, vertexArray);
				glDrawArrays(GL_LINES, 0, 2);
			}
		}

	}
	glFlush();

}

void MapDrawer::DrawCurrentCamera(const cv::Mat &M) {
	const float &w = mCameraSize;
	const float h = w * 0.75;
	const float z = w * 0.6;

	glPushMatrix();
	glMultMatrixf(M.ptr<GLfloat>(0));

	glLineWidth(mCameraLineWidth);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	GLfloat vertexArray[] = { 0, 0, 0, w, h, z, 0, 0, 0, w, -h, z, 0, 0, 0, -w,
			-h, z, 0, 0, 0, -w, h, z, w, h, z, w, -h, z, -w, h, z, -w, -h, z,
			-w, h, z, w, h, z, -w, -h, z, w, -h, z, };
	glVertexPointer(3, GL_FLOAT, 0, vertexArray);
	glDrawArrays(GL_LINES, 0, 16);
	glPopMatrix();

	glDisableClientState (GL_VERTEX_ARRAY);
	glDisable (GL_COLOR_MATERIAL);
}

void MapDrawer::SetCurrentCameraPose(const cv::Mat &Tcw) {
	unique_lock < mutex > lock(mMutexCamera);
	mCameraPose = Tcw.clone();
}

cv::Mat MapDrawer::GetCurrentOpenGLCameraMatrix() {
	cv::Mat M(4, 4, CV_32F);
	if (!mCameraPose.empty()) {
		cv::Mat Rwc(3, 3, CV_32F);
		cv::Mat twc(3, 1, CV_32F);
		{
			unique_lock < mutex > lock(mMutexCamera);
			Rwc = mCameraPose.rowRange(0, 3).colRange(0, 3).t();
			twc = -Rwc * mCameraPose.rowRange(0, 3).col(3);
		}
		M.at<float>(0, 0) = Rwc.at<float>(0, 0);
		M.at<float>(1, 0) = Rwc.at<float>(1, 0);
		M.at<float>(2, 0) = Rwc.at<float>(2, 0);
		M.at<float>(3, 0) = 0;
		M.at<float>(0, 1) = Rwc.at<float>(0, 1);
		M.at<float>(1, 1) = Rwc.at<float>(1, 1);
		M.at<float>(2, 1) = Rwc.at<float>(2, 1);
		M.at<float>(3, 1) = 0;
		M.at<float>(0, 2) = Rwc.at<float>(0, 2);
		M.at<float>(1, 2) = Rwc.at<float>(1, 2);
		M.at<float>(2, 2) = Rwc.at<float>(2, 2);
		M.at<float>(3, 2) = 0;
		M.at<float>(0, 3) = twc.at<float>(0);
		M.at<float>(1, 3) = twc.at<float>(1);
		M.at<float>(2, 3) = twc.at<float>(2);
		M.at<float>(3, 3) = 1.0;
	}
	return M;
}

} //namespace ORB_SLAM
