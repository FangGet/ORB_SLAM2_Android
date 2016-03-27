LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

include $(call all-subdir-makefiles)

include $(CLEAR_VARS)
LOCAL_MODULE:= lapack
LOCAL_SHORT_COMMANDS := true
LOCAL_STATIC_LIBRARIES := tmglib clapack blas f2c
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)
LOCAL_EXPORT_LDLIBS := $(LOCAL_LDLIBS)
include $(BUILD_SHARED_LIBRARY)