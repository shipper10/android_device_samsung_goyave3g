#Build libengbt
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false

LOCAL_SRC_FILES := bt_cmd_executer.c 

LOCAL_MODULE := libengbt
LOCAL_MODULE_TAGS := debug

LOCAL_SHARED_LIBRARIES += libcutils   \
                          libutils    \
                          libhardware \
                          libhardware_legacy \
			  libcutils
LOCAL_CFLAGS += $(GOYAVE3G_COMPAT_CFLAGS)
include $(BUILD_SHARED_LIBRARY)


