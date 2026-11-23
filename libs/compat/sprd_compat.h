/*
 * Compatibility definitions for the SPRD (SC8830) HAL sources that were written
 * against the KitKat/CM11 SPRD tree. They used to come from patches applied to
 * system/core, hardware/libhardware, frameworks/native and friends. On cm-14.1
 * they are injected into the device's own modules with "-include" instead
 * (see GOYAVE3G_COMPAT_CFLAGS in BoardConfig.mk), so no AOSP repo has to be patched.
 *
 * Everything is guarded, so this is harmless if upstream ever defines the names.
 * Values are the same as the old patches, except the FM audio devices which would
 * collide with AUDIO_DEVICE_OUT_BUS / _PROXY (0x1000000 / 0x2000000) on 7.1.
 */
#ifndef GOYAVE3G_SPRD_COMPAT_H
#define GOYAVE3G_SPRD_COMPAT_H

/* ---- system/graphics.h (HAL pixel formats) ---- */
#ifndef HAL_PIXEL_FORMAT_YCbCr_422_P
#define HAL_PIXEL_FORMAT_YCbCr_422_P        0x12
#endif
#ifndef HAL_PIXEL_FORMAT_YCbCr_420_P
#define HAL_PIXEL_FORMAT_YCbCr_420_P        0x13
#endif
#ifndef HAL_PIXEL_FORMAT_YCbCr_420_I
#define HAL_PIXEL_FORMAT_YCbCr_420_I        0x15
#endif
#ifndef HAL_PIXEL_FORMAT_CbYCrY_422_I
#define HAL_PIXEL_FORMAT_CbYCrY_422_I       0x16
#endif
#ifndef HAL_PIXEL_FORMAT_CbYCrY_420_I
#define HAL_PIXEL_FORMAT_CbYCrY_420_I       0x17
#endif
#ifndef HAL_PIXEL_FORMAT_YCbCr_420_SP_TILED
#define HAL_PIXEL_FORMAT_YCbCr_420_SP_TILED 0x18
#endif
#ifndef HAL_PIXEL_FORMAT_YCbCr_420_SP
#define HAL_PIXEL_FORMAT_YCbCr_420_SP       0x19
#endif
#ifndef HAL_PIXEL_FORMAT_YCrCb_420_SP_TILED
#define HAL_PIXEL_FORMAT_YCrCb_420_SP_TILED 0x1A
#endif
#ifndef HAL_PIXEL_FORMAT_YCrCb_422_SP
#define HAL_PIXEL_FORMAT_YCrCb_422_SP       0x1B
#endif
#ifndef HAL_PIXEL_FORMAT_YCrCb_420_P
#define HAL_PIXEL_FORMAT_YCrCb_420_P        0x1C
#endif

/* ---- ui/PixelFormat.h ---- */
#ifndef PIXEL_FORMAT_YCbCr_420_SP
#define PIXEL_FORMAT_YCbCr_420_SP           25
#endif

/* ---- hardware/gralloc.h (SPRD usage bits) ---- */
#ifndef GRALLOC_USAGE_OVERLAY_BUFFER
#define GRALLOC_USAGE_OVERLAY_BUFFER        0x01000000
#endif
#ifndef GRALLOC_USAGE_VIDEO_BUFFER
#define GRALLOC_USAGE_VIDEO_BUFFER          0x02000000
#endif
#ifndef GRALLOC_USAGE_CAMERA_BUFFER
#define GRALLOC_USAGE_CAMERA_BUFFER         0x04000000
#endif

/* ---- linux/fb.h ---- */
#ifndef FB_ACTIVATE_NODISP
#define FB_ACTIVATE_NODISP 1
#endif

/* ---- media/openmax (OMX_IVCommon.h / OMX_Index.h additions) ---- */
#ifndef OMX_SPRD_COLOR_FormatYVU420SemiPlanar
#define OMX_SPRD_COLOR_FormatYVU420SemiPlanar ((OMX_COLOR_FORMATTYPE)0x7FD00001)
#endif
#ifndef SPRD_INDEX_PARAM_ENABLE_ANB
#define SPRD_INDEX_PARAM_ENABLE_ANB "OMX.google.android.index.enableAndroidNativeBuffers"
#define OMX_IndexParamEnableAndroidBuffers  ((OMX_INDEXTYPE)0x7F000011)
#define SPRD_INDEX_PARAM_GET_ANB "OMX.google.android.index.getAndroidNativeBufferUsage"
#define OMX_IndexParamGetAndroidNativeBuffer ((OMX_INDEXTYPE)0x7F000012)
#define SPRD_INDEX_PARAM_USE_ANB "OMX.google.android.index.useAndroidNativeBuffer2"
#define OMX_IndexParamUseAndroidNativeBuffer2 ((OMX_INDEXTYPE)0x7F000013)
#define SPRD_INDEX_PARAM_STORE_METADATA_BUFFER "OMX.google.android.index.storeMetaDataInBuffers"
#define OMX_IndexParamStoreMetaDataBuffer   ((OMX_INDEXTYPE)0x7F000014)
#define SPRD_INDEX_PARAM_PREPEND_SPSPPS_TO_IDR "OMX.google.android.index.prependSPSPPSToIDRFrames"
#define OMX_IndexParamPrependSPSPPSToIDR    ((OMX_INDEXTYPE)0x7F000015)
#define SPRD_INDEX_CONFIG_THUMBNAIL_MODE "OMX.sprd.index.ThumbnailMode"
#define OMX_IndexConfigThumbnailMode        ((OMX_INDEXTYPE)0x7F000016)
#endif

/* ---- system/audio.h: SPRD FM routing devices ---- */
#ifndef AUDIO_DEVICE_OUT_ALL_FM
#define AUDIO_DEVICE_OUT_FM_HEADSET         0x4000000
#define AUDIO_DEVICE_OUT_FM_SPEAKER         0x8000000
#define AUDIO_DEVICE_OUT_ALL_FM             (AUDIO_DEVICE_OUT_FM_HEADSET | AUDIO_DEVICE_OUT_FM_SPEAKER)
#endif

#endif /* GOYAVE3G_SPRD_COMPAT_H */
