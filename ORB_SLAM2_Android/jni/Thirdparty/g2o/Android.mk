LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := g2o

SO_LIST:=$(wildcard $(LOCAL_PATH)/*.so)
LOCAL_SHARED_LIBRARIES:=$(SO_LIST:$(LOCAL_PATH)/%=%)

include $(BUILD_SHARED_LIBRARY)