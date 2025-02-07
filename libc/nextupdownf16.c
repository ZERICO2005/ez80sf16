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
#define Float16_pos_inf         UINT16_C(0x7C00)
#define Float16_neg_inf         UINT16_C(0xFC00)

__fp16_ABI nextupf(__fp16_ABI x) {
    F16_pun arg_x;
    arg_x.flt = x;

    if (_isnanf16(x) || arg_x.bin == Float16_pos_inf) {
        // return unmodified
        return x;
    }

    if (_iszerof16(x)) {
        F16_pun ret;
        ret.bin = Float16_pos_subnorm_min;
        return ret.flt;
    }

    if (_signbitf16(x)) {
        // Towards negative zero
        arg_x.bin--;
    } else {
        // Towards positive infinity
        arg_x.bin++;
    }
    return arg_x.flt;
}

__fp16_ABI nextdownf(__fp16_ABI x) {
    F16_pun arg_x;
    arg_x.flt = x;

    if (_isnanf16(x) || arg_x.bin == Float16_neg_inf) {
        // return unmodified
        return x;
    }

    if (_iszerof16(x)) {
        F16_pun ret;
        ret.bin = Float16_neg_subnorm_min;
        return ret.flt;
    }
    
    if (_signbitf16(x)) {
        // Towards negative infinity
        arg_x.bin++;
    } else {
        // Towards positive zero
        arg_x.bin--;
    }
    return arg_x.flt;
}
