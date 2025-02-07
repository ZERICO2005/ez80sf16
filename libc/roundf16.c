#include <math.h>
#include <stdint.h>
#include <float16.h>

__fp16_ABI roundf16(__fp16_ABI x)
{
    struct {
        __fp16_ABI flt;
        uint16_t bin;
    } one_half;
    one_half.bin = 0x3800;
    return truncf16(C_hadd(x, copysignf16(one_half.flt, x)));
}
