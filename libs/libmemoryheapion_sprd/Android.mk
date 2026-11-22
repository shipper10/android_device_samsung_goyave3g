LOCAL_PATH := $(call my-dir)

# SPRD MemoryHeapIon (ION heap with SPRD custom ioctls: phys addr, iova, msync).
# Replaces the old frameworks/native libbinder patch (MemoryHeapIon.SPRD.{h,cpp}).
include $(CLEAR_VARS)

LOCAL_MODULE := libmemoryheapion_sprd
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES

LOCAL_SRC_FILES := MemoryHeapIon.cpp

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/include

LOCAL_EXPORT_C_INCLUDE_DIRS := \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/include

LOCAL_CFLAGS := -Wno-unused-parameter -Wno-format -Wno-pointer-arith

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	liblog \
	libcutils \
	libutils

include $(BUILD_SHARED_LIBRARY)
