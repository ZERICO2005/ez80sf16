#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <float16.h>

#define Float16_nan_mask UINT16_C(0x01FF)
#define Float16_pos_nan  UINT16_C(0x7E00)

__fp16_ABI nanf16(const char *tag)
{
    return (union { uint16_t u; __fp16_ABI f; }) {
        .u = ((uint16_t)strtol(tag, NULL, 0) & Float16_nan_mask) | Float16_pos_nan,
    }.f;
}
