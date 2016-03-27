LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE:=DLib

LOCAL_C_INCLUDES:=$(LOCAL_PATH)/include/DUtils
FILE_LIST:=$(wildcard $(LOCAL_PATH)/src/DUtils/*.cpp)
LOCAL_SRC_FILES:=$(FILE_LIST:$(LOCAL_PATH)/%=%)


FILE_LIST:=$(wildcard $(LOCAL_PATH)/src/DUtilsCV/*.cpp)
LOCAL_SRC_FILES+=$(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES+=$(LOCAL_PSTH)/include/DUtilsCV

FILE_LIST:=$(wildcard $(LOCAL_PATH)/src/DVision/*.cpp)
LOCAL_SRC_FILES+=$(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES+=$(LOCAL_PATH)/include/DVision

LOCAL_LDLIBS := -lm
LOCAL_LDLIBS += -lopencv
LOCAL_LDLIBS += -llog

include $(BUILD_SHARED_LIBRARY)

