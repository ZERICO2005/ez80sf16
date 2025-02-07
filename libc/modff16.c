#include <math.h>
#include <stdint.h>
#include <float16.h>

__fp16_ABI modff16(__fp16_ABI x, __fp16_ABI *integral_part) {
    switch (_fpclassifyf16(x)) {
        case FP_ZERO:
        case FP_NAN: {
            *integral_part = x;
            return x;
        }
        case FP_INFINITY: {
            *integral_part = x;
            struct {
                __fp16_ABI flt;
                uint16_t bin;
            } ret_zero;
            ret_zero.bin = 0x0000;
            return copysignf16(ret_zero.flt, x);
        }
        case FP_SUBNORMAL:
        case FP_NORMAL:
    }
    long double trunc_x = truncf16(x);
    *integral_part = x;
    // result will be exact, and should not raise exceptions
    return C_hsub(x, trunc_x);
}
