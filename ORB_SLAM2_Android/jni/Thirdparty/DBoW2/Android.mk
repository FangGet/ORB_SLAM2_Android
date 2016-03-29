LOCAL_PATH:= $(call my-dir)

#include $(CLEAR_VARS)
#
#include $(LOCAL_PATH)/DLib/Android.mk

include $(CLEAR_VARS)

LOCAL_MODULE :=DBoW2
LOCAL_SRC_FILES:=test.cpp

#LOCAL_STATIC_LIBRARIES:=DLib

#LOCAL_C_INCLUDES:=$(LOCAL_PATH)/include/DBoW2

#LOCAL_CFLAGS += -I$(LOCAL_PATH)/../Boost/include/boost-1_49/boost/
#LOCAL_LDLIBS += -L$(LOCAL_PATH)/../Boost/lib/ -lboost_system -lboost_...
#LOCAL_CPPFLAGS += -fexceptions
#LOCAL_CPPFLAGS += -frtti

#FILE_LIST:=$(wildcard $(LOCAL_PATH)/src/*.cpp)
#LOCAL_SRC_FILES:=$(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_SHARED_LIBRARIES:=libopencc
#LOCAL_LDLIBS:=-lopencv

include $(BUILD_SHARED_LIBRARY)