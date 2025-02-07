#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <float16.h>

typedef union F16_pun {
    __fp16_ABI flt;
    uint16_t bin;
    struct {
        uint8_t L;
        uint8_t H;
    } reg;
} F16_pun;

#define Float16_ilogb_subnorm_max -15
#define Float16_exp_bias          15
#define Float16_mantissa_bits     10

#define Float16_exponent_bits  5
#define Float16_sign_bits      1

#define uint8_bits 8

/**
 * @note x is assumed to be positive
 */
int _ilogbf16_c(__fp16_ABI x) {
    F16_pun val;
    val.flt = x;
    int fp_class = _fpclassifyf16(val.flt);
    switch(fp_class) {
        case FP_ZERO: {
            errno = EDOM;
            feraiseexcept(FE_INVALID);
            return FP_ILOGB0;
        }
        case FP_INFINITE: {
            errno = EDOM;
            feraiseexcept(FE_INVALID);
            return INT_MAX;
        }
        case FP_NAN: {
            errno = EDOM;
            feraiseexcept(FE_INVALID);
            return FP_ILOGBNAN;
        }
        case FP_NORMAL: {
            int x_exp = (int)(val.reg.H >> (Float16_mantissa_bits - uint8_bits));
            x_exp -= Float16_exp_bias;
            return x_exp;
        }
        case FP_SUBNORMAL: {
            const int clz_offset = Float16_exponent_bits + Float16_sign_bits;
            return (Float16_ilogb_subnorm_max + clz_offset) - (
                __builtin_clz(val.bin) - ((sizeof(unsigned int) - sizeof(uint16_t)) * CHAR_BIT)
            );
        }
        default:
            __builtin_unreachable();
    }
}
