LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)  

OPENCV_LIB_TYPE:=STATIC
#ifeq ("$(wildcard $(OPENCV_MK_PATH))","")  
#include $(LOCAL_PATH)/OpenCV.mk
#else  
#include $(OPENCV_MK_PATH)  
#endif  

include $(LOCAL_PATH)/OpenCV.mk

LOCAL_MODULE    := opencv  

include $(BUILD_SHARED_LIBRARY) 