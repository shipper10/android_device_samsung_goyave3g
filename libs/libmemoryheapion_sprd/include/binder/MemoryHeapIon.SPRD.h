/*
 * Compatibility header: the KitKat SPRD stack patched libbinder to provide
 * <binder/MemoryHeapIon.SPRD.h>. On cm-14.1 the class lives in the device's own
 * libmemoryheapion_sprd instead, so libbinder no longer needs to be patched.
 */
#ifndef GOYAVE3G_BINDER_MEMORYHEAPION_SPRD_H
#define GOYAVE3G_BINDER_MEMORYHEAPION_SPRD_H
#include <MemoryHeapIon.h>
#endif
