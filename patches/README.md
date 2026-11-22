# Patches

`cm-14.1/` – the only patches the cm-14.1 build needs (applied by the build workflow, idempotently):

| patch | repo | why |
|---|---|---|
| external_tinyalsa.diff | external/tinyalsa | adds `pcm_set_samplerate()` used by the SPRD audio HAL |
| frameworks_av.diff | frameworks/av | ACodec: SPRD decoders render with the SPRD gralloc pixel formats |

Everything else the old KitKat patches did is done inside this device tree instead:
MemoryHeapIon -> `libs/libmemoryheapion_sprd`, ION -> `libs/libion_sprd`, pixel formats / gralloc
usage bits / OMX indices / FM audio devices -> `libs/compat/sprd_compat.h`
(injected with `GOYAVE3G_COMPAT_CFLAGS`).

`legacy-cm11/` – the original KitKat-era patches, kept for reference only (do NOT apply).
