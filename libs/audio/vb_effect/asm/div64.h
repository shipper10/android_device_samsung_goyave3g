#ifndef _VB_EFFECT_LOCAL_ASM_DIV64_H
#define _VB_EFFECT_LOCAL_ASM_DIV64_H
#include <stdint.h>

#define do_div(n, base) ({ \
    uint32_t __base = (base); \
    uint32_t __rem; \
    __rem = ((uint64_t)(n)) % __base; \
    (n) = ((uint64_t)(n)) / __base; \
    __rem; \
})

static inline uint64_t div_u64_rem(uint64_t dividend, uint32_t divisor, uint32_t *remainder) {
    *remainder = dividend % divisor;
    return dividend / divisor;
}

static inline uint64_t div_u64(uint64_t dividend, uint32_t divisor) {
    return dividend / divisor;
}

static inline int64_t div_s64(int64_t dividend, int32_t divisor) {
    return dividend / divisor;
}
#endif
