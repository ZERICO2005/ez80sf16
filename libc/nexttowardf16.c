#include <fenv.h>
#include <math.h>
#include <stdint.h>
#include <float16.h>

typedef union F64_pun {
    long double flt;
    uint64_t bin;
} F64_pun;

typedef union F16_pun {
    __fp16_ABI flt;
    uint16_t bin;
} F16_pun;

#define Float16_pos_subnorm_min UINT16_C(0x0001)
#define Float16_neg_subnorm_min UINT16_C(0x8001)
#define Float16_pos_nan         UINT16_C(0x7E00)

__fp16_ABI nexttowardf16(__fp16_ABI x, long double y) {
    F16_pun arg_x;
    arg_x.flt = x;

    if (_isnanf16(x)) {
        return x;
    }

    if (isnan(y)) {
        F16_pun ret;
        ret.bin = Float16_pos_nan;
        return ret.flt;
    }
    
    F64_pun x_f64, y_f64;
	x_f64.flt = C_htod(x);
    y_f64.flt = y;
    if (x_f64.bin == y_f64.bin) {
        // return unmodified
        return x;
    }

    if (_iszerof16(x)) {
        F16_pun ret;
        ret.bin = signbit(y) ? Float16_neg_subnorm_min : Float16_pos_subnorm_min;
        if (iszero(y)) {
            // pos_subnorm_min becomes +0.0, and neg_subnorm_min becomes -0.0
            ret.bin--;
        } else {
            feraiseexcept(FE_INEXACT | FE_UNDERFLOW);
        }
        return ret.flt;
    }
    if (isless(x_f64.flt, y) != _signbitf16(x)) {
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

double nexttoward(double, long double) __attribute__((alias("nexttowardf")));

/* nexttowardl is aliased in nextafter.c */
