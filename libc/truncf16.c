#include <fenv.h>
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

#define Float16_bias 15
#define Float16_mantissa_bits 10
#define uint8_bits 8

/** @note x is assumed to be positive */
__fp16_ABI _truncf16_c(__fp16_ABI x) {
    F16_pun val;
    val.flt = x;
    uint8_t expon = val.reg.H >> (Float16_mantissa_bits - uint8_bits);
    expon -= Float16_bias;
    if (expon < 0) {
        // truncate to zero (x is less than one)
        val.bin = 0;
        return val.flt;
    }
    if (expon >= Float16_mantissa_bits) {
        // guaranteed to be an integer, infinty, or NaN
        return val.flt;
    }
    uint16_t mask = UINT16_MAX << (Float16_mantissa_bits - expon);
    val.bin &= mask;
    return val.flt;
}
