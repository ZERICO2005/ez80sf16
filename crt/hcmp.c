#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <float16.h>

typedef union F16_pun {
	__fp16_ABI flt;
    uint16_t bin;
} F16_pun;

#define F16_CMP_EQUAL      0 /* sets the Z flag */
#define F16_CMP_LESS      -1 /* sets the S flag */
#define F16_CMP_GREATER    1 /* doesn't trigger flags */
#define F16_CMP_UNORDERED  1 /* doesn't trigger flags */

// assumes no NaN
int _hcmp_c(__fp16_ABI x, __fp16_ABI y) {
    F16_pun arg_x, arg_y;
    arg_x.flt = x;
    arg_y.flt = y;

    bool x_sign = _signbitf16(arg_x.flt);
    bool y_sign = _signbitf16(arg_y.flt);
    if (x_sign != y_sign) {
        if (_iszerof16(arg_x.flt) && _iszerof16(arg_y.flt)) {
            return F16_CMP_EQUAL;
        }
        return (x_sign ? F16_CMP_LESS : F16_CMP_GREATER);
    }
    
    if (arg_x.bin == arg_y.bin) {
        return F16_CMP_EQUAL;
    }
    return ((arg_x.bin < arg_y.bin) != x_sign) ? F16_CMP_LESS : F16_CMP_GREATER;
}
