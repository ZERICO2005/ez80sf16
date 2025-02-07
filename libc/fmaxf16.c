#include <math.h>
#include <float16.h>

__fp16_ABI fmaxf16(__fp16_ABI x, __fp16_ABI y) {
    return
        (C_hcmp(x, y) < 0) ? y :
        (C_hcmp(y, x) < 0) ? x :
        /* attempts to return a non-NaN value */
        _isnanf16(x) ? y :
        _isnanf16(y) ? x :
        /* arguments are equal or signed zero */
        _signbitf16(x) ? y : x;
}
