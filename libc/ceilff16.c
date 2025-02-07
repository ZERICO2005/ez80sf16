#include <math.h>
#include <stdint.h>
#include <float16.h>

typedef union F16_pun {
    __fp16_ABI flt;
    uint16_t bin;
} F16_pun;

#define Float16_pos_zero UINT16_C(0x0000)

__fp16_ABI ceilf16(__fp16_ABI x) {
    if (_signbitf16(x)) {
        return truncf16(x);
    }
    if (!_isfinitef16(x)) {
        return x;
    }
    F16_pun frac;
    frac.flt = modff16(x, &x);
    if (frac.bin != Float16_pos_zero) {
        F16_pun one_value;
        one_value.bin = 0x3C00;
        x = C_hadd(x, one_value.flt);
    }
    return x;
}
