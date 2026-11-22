LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	SprdOMXPlugin.cpp \
	SprdOMXComponent.cpp \
	SprdSimpleOMXComponent.cpp

LOCAL_CFLAGS := $(PV_CFLAGS_MINUS_VISIBILITY)

LOCAL_C_INCLUDES:= \
	frameworks/native/include/media/openmax \
	frameworks/native/include/media/hardware \
	$(LOCAL_PATH)/include \
	$(LOCAL_PATH)/../gralloc \
	$(LOCAL_PATH)/include

LOCAL_EXPORT_C_INCLUDE_DIRS := \
	$(LOCAL_PATH)/include

LOCAL_SHARED_LIBRARIES :=       \
        libbinder               \
        libmemoryheapion_sprd               \
        libutils                \
        libcutils               \
        libui                   \
        libdl			\
	libstagefright_foundation

LOCAL_MODULE := libstagefrighthw

LOCAL_CFLAGS:= -DLOG_TAG=\"$(TARGET_BOARD_PLATFORM).libstagefright\"

LOCAL_CFLAGS += $(GOYAVE3G_COMPAT_CFLAGS)
include $(BUILD_SHARED_LIBRARY)

