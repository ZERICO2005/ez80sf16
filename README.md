The CE C/C++ toolchain doesn't support `__fp16` right now, so `__fp16_ABI` is offered as a placeholder for development purposes.

# float16.h

`<float16.h>` contains prototypes for 16 bit float functions and libcalls. It also contains a `float16` class, which allows you to use `__fp16_ABI` like a regular float/double.

`__fp16_ABI` is currently a typedef for `uint16_t`, so using arithmetic operators directly on the type will lead to unexpected results.

# libcalls

libcalls can be called regularly from assembly, but they need a wrapper to use in C.

If you want to add two `__fp16` numbers in C, you can call `__hadd` in assembly, or `C_hadd(x, y)` in C, which will wrap the libcall.

For comparisons, you can use `C_hcmp(x, y)` and test `== 0` for equals, `< 0` for less-than, and `<= 0` for less-than or equal.

# ieee compliance

Ideally, `__fp16` should be able to support the following:
- signed zeros
- subnormals
- infinity
- quiet NaNs
- rounding to nearest with ties to even
- FE_INVALID, FE_OVERFLOW, FE_DIVBYZERO

Additional rounding modes and signalling NaNs are not needed.

For `__fp16` to be merged into the toolchain, it should support the following functions:
- hneg, hcmp, hadd, hsub, hmul, fmaf16
- hdiv, hrem, fmodf16, sqrtf16
- htof, htod, htoi, htou
- ftoh, dtoh, itoh, utoh, lltoh, ulltoh
