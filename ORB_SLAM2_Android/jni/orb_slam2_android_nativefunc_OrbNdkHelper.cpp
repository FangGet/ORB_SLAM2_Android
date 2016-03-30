#include "orb_slam2_android_nativefunc_OrbNdkHelper.h"
#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>
#include<opencv2/core/core.hpp>
#include<System.h>
using namespace cv;

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
	ORB_SLAM2::System SLAM(voc_string,cal_string,ORB_SLAM2::System::MONOCULAR,true);
	env->ReleaseStringUTFChars(calibrationPath, calChar);
	env->ReleaseStringUTFChars(VOCPath, vocChar);
}

/*
 * Class:     orb_slam2_android_nativefunc_OrbNdkHelper
 * Method:    startCurrentORB
 * Signature: (DDD[I)[I
 */
JNIEXPORT jintArray JNICALL Java_orb_slam2_android_nativefunc_OrbNdkHelper_startCurrentORB(
		JNIEnv * env, jclass cls, jdouble curTimeStamp, jintArray buf, jint w,
		jint h) {
	jint *cbuf;
	cbuf = env->GetIntArrayElements(buf, false);
	if (cbuf == NULL) {
		return 0;
	}
	int size=w * h;
	cv::Mat myimg(h, w, CV_8UC4, (unsigned char*) cbuf);

	ORB_SLAM2::System *s =ORB_SLAM2::System::get_instance();
	s->TrackMonocular(myimg,curTimeStamp);

	//jintArray result = (jintArray)resultImg.data;
	env->ReleaseIntArrayElements(buf, cbuf, 0);
	//return result;return buf;
	return buf;
}

