LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
include $(LOCAL_PATH)/Config.mk

LOCAL_MODULE:= blas
LOCAL_CFLAGS:= -O3 -fPIC
LOCAL_SRC_FILES:= $(ALLOBJ)  
LOCAL_SHORT_COMMANDS := true

#the inclusion of BLASWRAP caused unresolved symbols for TooN
#LOCAL_CFLAGS:= -DNO_BLAS_WRAP

include $(BUILD_STATIC_LIBRARY)

#include $(CLEAR_VARS)
#include $(LOCAL_PATH)/Config.mk
#
#LOCAL_MODULE:= f2cblas
#LOCAL_CFLAGS:= -O3 -fPIC
#LOCAL_SRC_FILES:= $(ALLOBJ)  
#
#include $(BUILD_STATIC_LIBRARY)
