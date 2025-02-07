#include <math.h>
#include <float16.h>

__fp16_ABI fdimf16(__fp16_ABI x, __fp16_ABI y) {
    /**
     * returns `x - y` when `x > y` or if one of the arguments is NaN.
     * Otherwise returns positive zero.
     */
    struct {
        __fp16_ABI flt;
        uint16_t bin;
    } ret_zero;
    ret_zero.bin = 0x0000;
    return (C_hcmp(x, y) <= 0) ? ret_zero.flt : C_hsub(x, y);
}
