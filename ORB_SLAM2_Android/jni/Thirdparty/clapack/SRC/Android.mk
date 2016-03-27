LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
include $(LOCAL_PATH)/Config.mk

LOCAL_MODULE:= clapack
LOCAL_CFLAGS:= -O3 -fPIC
LOCAL_SRC_FILES:= $(ALLOBJ)

include $(BUILD_STATIC_LIBRARY)
