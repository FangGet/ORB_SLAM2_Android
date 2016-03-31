#include "orb_slam2_android_nativefunc_OrbNdkHelper.h"
#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>
#include<opencv2/core/core.hpp>
#include<System.h>
using namespace cv;
#include <android/log.h>
#define LOG_TAG "ORB_SLAM_SYSTEM"

#define LOG(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)
static ORB_SLAM2::System *s;

/*
 * Class:     orb_slam2_android_nativefunc_OrbNdkHelper
 * Method:    initSystemWithParameters
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_orb_slam2_android_nativefunc_OrbNdkHelper_initSystemWithParameters
(JNIEnv * env, jclass cls, jstring VOCPath, jstring calibrationPath) {
	const char *calChar = env->GetStringUTFChars(calibrationPath, JNI_FALSE);
	const char *vocChar = env->GetStringUTFChars(VOCPath, JNI_FALSE);
	// use your string
	std::string voc_string(vocChar);
	std::string cal_string(calChar);

	env->GetJavaVM(&jvm);
	jvm->AttachCurrentThread(&env, NULL);
//	if(voc_string.size()==0&&cal_string.size()==0)
//		return; "/storage/emulated/0/ORBvoc.txt""/storage/emulated/0/TUM1.yaml"
	// Create SLAM system. It initializes all system threads and gets ready to process frames.
	s=new ORB_SLAM2::System(voc_string,cal_string,ORB_SLAM2::System::MONOCULAR,true);
	env->ReleaseStringUTFChars(calibrationPath, calChar);
	env->ReleaseStringUTFChars(VOCPath, vocChar);
}

/*
 * Class:     orb_slam2_android_nativefunc_OrbNdkHelper
 * Method:    startCurrentORB
 * Signature: (DDD[I)[I
 */
JNIEXPORT jint JNICALL Java_orb_slam2_android_nativefunc_OrbNdkHelper_startCurrentORB(
		JNIEnv * env, jclass cls, jdouble curTimeStamp, jintArray buf, jint w,
		jint h) {
	jint *cbuf;
	cbuf = env->GetIntArrayElements(buf, false);
	if (cbuf == NULL) {
		return 0;
	}
	int size=w * h;
	cv::Mat myimg(h, w, CV_8UC4, (unsigned char*) cbuf);
	cv::Mat ima=s->TrackMonocular(myimg,curTimeStamp);
	if((ima.rows == 4)&(ima.cols == 4)) {
	        LOG("mCurrentFrame.mTcw [1][1] %f  ", ima.at<float>(0, 0));
	        LOG("mCurrentFrame.mTcw [1][2] %f  ", ima.at<float>(0, 1));
	        LOG("mCurrentFrame.mTcw [1][3] %f  ", ima.at<float>(0, 2));
	        LOG("mCurrentFrame.mTcw [1][4] %f  ", ima.at<float>(0, 3));
	        LOG("mCurrentFrame.mTcw [2][1] %f  ", ima.at<float>(1, 0));
	        LOG("mCurrentFrame.mTcw [2][2] %f  ", ima.at<float>(1, 1));
	        LOG("mCurrentFrame.mTcw [2][3] %f  ", ima.at<float>(1, 2));
	        LOG("mCurrentFrame.mTcw [2][4] %f  ", ima.at<float>(1, 3));
	        LOG("mCurrentFrame.mTcw [3][1] %f  ", ima.at<float>(2, 0));
	        LOG("mCurrentFrame.mTcw [3][2] %f  ", ima.at<float>(2, 1));
	        LOG("mCurrentFrame.mTcw [3][3] %f  ", ima.at<float>(2, 2));
	        LOG("mCurrentFrame.mTcw [3][4] %f  ", ima.at<float>(2, 3));
	        LOG("mCurrentFrame.mTcw [4][1] %f  ", ima.at<float>(3, 0));
	        LOG("mCurrentFrame.mTcw [4][2] %f  ", ima.at<float>(3, 1));
	        LOG("mCurrentFrame.mTcw [4][3] %f  ", ima.at<float>(3, 2));
	        LOG("mCurrentFrame.mTcw [4][4] %f  ", ima.at<float>(3, 3));
	 }
	//env->ReleaseIntArrayElements(array, result, 0);
	env->ReleaseIntArrayElements(buf, cbuf, 0);
//	return array;
	return ima.dims;
	//return buf;
}

