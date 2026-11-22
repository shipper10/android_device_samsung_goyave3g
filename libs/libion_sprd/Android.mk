LOCAL_PATH := $(call my-dir)

# ION userspace library with the SPRD/KitKat-style API (struct ion_handle *,
# ion_invalidate_fd). Used by gralloc and hwcomposer. It deliberately does NOT
# replace the system libion.so (no vendor blob uses libion).
include $(CLEAR_VARS)

LOCAL_MODULE := libion_sprd
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES

LOCAL_SRC_FILES := ion.c

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH)/include

LOCAL_CFLAGS := -Wno-unused-parameter

LOCAL_SHARED_LIBRARIES := liblog libcutils

include $(BUILD_SHARED_LIBRARY)
