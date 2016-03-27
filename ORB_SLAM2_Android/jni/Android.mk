LOCAL_PATH:= $(call my-dir)

#include $(CLEAR_VARS)  
#OPENCV_LIB_TYPE:=STATIC
#ifeq ("$(wildcard $(OPENCV_MK_PATH))","")  
##try to load OpenCV.mk from default install location  
#include C:\Users\213\workspace\OpenCV-2.4.9-android-sdk\sdk\native\jni\OpenCV.mk
#else  
#include $(OPENCV_MK_PATH)  
#endif  
#LOCAL_MODULE    := ImgFun  
#LOCAL_SRC_FILES := ImgFun.cpp  
#include $(BUILD_SHARED_LIBRARY) 

#include $(CLEAR_VARS)
#LOCAL_MODULE:= testlapack
#LOCAL_SRC_FILES:= testclapack.cpp
#LOCAL_STATIC_LIBRARIES := lapack
#include $(BUILD_SHARED_LIBRARY)

#include $(CLEAR_VARS)
#MAIN_DIR:=$(LOCAL_PATH)
#include $(LOCAL_PATH)/Thirdparty/g2o/Android.mk
#LOCAL_PATH:=$(MAIN_DIR)
#
#include $(CLEAR_VARS)
#MAIN_DIR:=$(LOCAL_PATH)
#include $(LOCAL_PATH)/Thirdparty/opencv/Android.mk
#LOCAL_PATH:=$(MAIN_DIR)
#
#include $(CLEAR_VARS)
#
#include $(LOCAL_PATH)/Thirdparty/DBoW2/Android.mk


include $(CLEAR_VARS)  

#OPENCV_LIB_TYPE:=STATIC
#ifeq ("$(wildcard $(OPENCV_MK_PATH))","")  
#include $(LOCAL_PATH)/Thirdparty/opencv/OpenCV.mk
#else  
#include $(OPENCV_MK_PATH)  
#endif  
LOCAL_SRC_FILES:=test.cpp
LOCAL_MODULE    := opencv  
include $(BUILD_SHARED_LIBRARY) 

include $(CLEAR_VARS)
include $(LOCAL_PATH)/Thirdparty/DBoW2/Android.mk

include $(CLEAR_VARS)

LOCAL_MODULE:=ORB_SLAM2
#LOCAL_SHARED_LIBRARIES :=g2o
#LOCAL_SHARED_LIBRARIES +=DBoW2

#LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
