#include <fenv.h>
#include <math.h>
#include <float16.h>

__fp16_ABI logbf16(__fp16_ABI x) {
    if (_isfinitef16(x)) {
        if (_iszerof16(x)) {
            feraiseexcept(FE_DIVBYZERO);
            struct {
                __fp16_ABI flt;
                uint16_t bin;
            } ret_neg_inf;
            ret_neg_inf.bin = 0xFC00;
            return ret_neg_inf.flt;
        }
        return C_itof16(ilogbf16(x));
    }
    // infinity and NaN
    return fabsf16(x);
}
