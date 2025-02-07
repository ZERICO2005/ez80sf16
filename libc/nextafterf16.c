#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <float16.h>

typedef union F16_pun {
    __fp16_ABI flt;
    uint16_t bin;
} F16_pun;

#define Float16_pos_subnorm_min UINT16_C(0x0001)
#define Float16_neg_subnorm_min UINT16_C(0x8001)

__fp16_ABI nextafterf16(__fp16_ABI x, __fp16_ABI y) {
    F16_pun arg_x, arg_y;
    arg_x.flt = x;
    arg_y.flt = y;

    if (_isnanf16(y)) {
        return y;
    }
    if (_isnanf16(x)) {
        return x;
    }
    if (arg_x.bin == arg_y.bin) {
        return y;
    }

    if (_iszerof16(x)) {
        if (_iszerof16(y)) {
            // special case where `+0.0 --> -0.0` and `-0.0 --> +0.0`
            return y;
        }
        feraiseexcept(FE_INEXACT | FE_UNDERFLOW);
        F16_pun ret;
        ret.bin = _signbitf16(y) ? Float16_neg_subnorm_min : Float16_pos_subnorm_min;
        return ret.flt;
    }
    if ((C_hcmp(x, y) < 0) != _signbitf16(x)) {
        // Towards positive/negative infinity
        arg_x.bin++;
    } else {
        // Towards negative/positive zero
        arg_x.bin--;
    }
    if (_isnormalf16(arg_x.flt)) {
        return arg_x.flt;
    }
    if (_isinff16(arg_x.flt)) {
        // overflow to infinity
        feraiseexcept(FE_INEXACT | FE_OVERFLOW);
    } else {
        // result is subnormal or zero
        feraiseexcept(FE_INEXACT | FE_UNDERFLOW);
    }
    return arg_x.flt;
}
