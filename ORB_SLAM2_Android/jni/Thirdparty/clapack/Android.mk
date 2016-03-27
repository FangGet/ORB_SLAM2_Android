LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

export CLAPACK_TOP:= $(LOCAL_PATH)


subdirs := $(addprefix $(LOCAL_PATH)/,$(addsuffix /Android.mk, \
                F2CLIBS/libf2c \
                BLAS/SRC  \
                SRC/VARIANTS \
                SRC \
        ))

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/INCLUDE

include $(subdirs)
