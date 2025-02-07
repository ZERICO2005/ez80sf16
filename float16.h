#ifndef FLOAT16_H
#define FLOAT16_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef uint16_t __fp16_ABI;

/* libcalls */

__fp16_ABI C_hneg(__fp16_ABI);
__fp16_ABI C_hadd(__fp16_ABI, __fp16_ABI);
__fp16_ABI C_hsub(__fp16_ABI, __fp16_ABI);
__fp16_ABI C_hmul(__fp16_ABI, __fp16_ABI);
__fp16_ABI C_hdiv(__fp16_ABI, __fp16_ABI);
__fp16_ABI C_hrem(__fp16_ABI, __fp16_ABI);

/* -1 LESS, 0 EQUAL, 1 GREATER */
int C_hcmp(__fp16_ABI, __fp16_ABI);
int C_hcmpo(__fp16_ABI, __fp16_ABI);
int C_hcmpu(__fp16_ABI, __fp16_ABI);

int C_htoi(__fp16_ABI);
unsigned int C_htou(__fp16_ABI);
float C_htof(__fp16_ABI);
long double C_htod(__fp16_ABI);

__fp16_ABI C_itof16(int);
__fp16_ABI C_utof16(unsigned int);
__fp16_ABI C_ftof16(__fp16_ABI);
__fp16_ABI C_dtof16(__fp16_ABI);

/* primative functions */

__fp16_ABI fabsf16(__fp16_ABI);
__fp16_ABI copysignf16(__fp16_ABI, __fp16_ABI);
__fp16_ABI fmodf16(__fp16_ABI, __fp16_ABI);
__fp16_ABI fmaf16(__fp16_ABI, __fp16_ABI, __fp16_ABI);

bool _signbitf16(__fp16_ABI);
int _isinff16(__fp16_ABI);
int _isnanf16(__fp16_ABI);
int _isnormalf16(__fp16_ABI);
int _isfinitef16(__fp16_ABI);
int _iszerof16(__fp16_ABI);
int _issubnormalf16(__fp16_ABI);
int _fpclassifyf16(__fp16_ABI);

__fp16_ABI fmaxf16(__fp16_ABI, __fp16_ABI);
__fp16_ABI fminf16(__fp16_ABI, __fp16_ABI);
__fp16_ABI fdimf16(__fp16_ABI, __fp16_ABI);

/* manipulation */

__fp16_ABI nextafterf16(__fp16_ABI, __fp16_ABI);
__fp16_ABI nextupf16(__fp16_ABI);
__fp16_ABI nextdownf16(__fp16_ABI);
__fp16_ABI nexttowardf16(__fp16_ABI, long double);

int ilogbf16(__fp16_ABI);
__fp16_ABI frexpf16(__fp16_ABI, int*);
__fp16_ABI ldexpf16(__fp16_ABI, int);
__fp16_ABI scalbnf16(__fp16_ABI, int);
__fp16_ABI scalblnf16(__fp16_ABI, long);
__fp16_ABI logbf16(__fp16_ABI);

/* string */

__fp16_ABI nanf16(const char*);
__fp16_ABI strtof16(const char *__restrict nptr, char **__restrict endptr);

/* rounding */

__fp16_ABI truncf16(__fp16_ABI);
__fp16_ABI modff16(__fp16_ABI, __fp16_ABI*);

__fp16_ABI floorf16(__fp16_ABI);
__fp16_ABI ceilf16(__fp16_ABI);
__fp16_ABI roundf16(__fp16_ABI);
__fp16_ABI roundevenf16(__fp16_ABI);
__fp16_ABI nearbyintf16(__fp16_ABI);
__fp16_ABI rintf16(__fp16_ABI);

long lroundf16(__fp16_ABI);
long lrintf16(__fp16_ABI);
long long llroundf16(__fp16_ABI);
long long llrintf16(__fp16_ABI);

/* remainder */

__fp16_ABI remainderf16(__fp16_ABI, __fp16_ABI);
__fp16_ABI remquof16(__fp16_ABI, __fp16_ABI, int*);

/* exponents and logarithms */

__fp16_ABI expf16(__fp16_ABI);
__fp16_ABI expm1f16(__fp16_ABI);

__fp16_ABI logf16(__fp16_ABI);
__fp16_ABI log1pf16(__fp16_ABI);

__fp16_ABI powf16(__fp16_ABI, __fp16_ABI);
__fp16_ABI powrf16(__fp16_ABI, __fp16_ABI);

__fp16_ABI hypotf16(__fp16_ABI, __fp16_ABI);
__fp16_ABI cbrtf16(__fp16_ABI);
__fp16_ABI rsqrtf16(__fp16_ABI);

__fp16_ABI exp2f16(__fp16_ABI);
__fp16_ABI exp10f16(__fp16_ABI);
__fp16_ABI log2f16(__fp16_ABI);
__fp16_ABI log10f16(__fp16_ABI);
__fp16_ABI logbf16(__fp16_ABI);

/* trigonometry */

__fp16_ABI sinf16(__fp16_ABI);
__fp16_ABI cosf16(__fp16_ABI);
__fp16_ABI tanf16(__fp16_ABI);
void sincosf16(__fp16_ABI, __fp16_ABI*, __fp16_ABI*);
__fp16_ABI asinf16(__fp16_ABI);
__fp16_ABI acosf16(__fp16_ABI);
__fp16_ABI atanf16(__fp16_ABI);
__fp16_ABI atan2f16(__fp16_ABI, __fp16_ABI);

/* hyperbolic trigonometry */

__fp16_ABI sinhf16(__fp16_ABI);
__fp16_ABI coshf16(__fp16_ABI);
__fp16_ABI tanhf16(__fp16_ABI);
void sinhcoshf16(__fp16_ABI, __fp16_ABI*, __fp16_ABI*);
__fp16_ABI asinhf16(__fp16_ABI);
__fp16_ABI acoshf16(__fp16_ABI);
__fp16_ABI atanhf16(__fp16_ABI);

/* transcendental */

__fp16_ABI lgammaf16(__fp16_ABI);
__fp16_ABI tgammaf16(__fp16_ABI);
__fp16_ABI erff16(__fp16_ABI);
__fp16_ABI erfcf16(__fp16_ABI);

/* C++ struct */

typedef struct float16 {
	__fp16_ABI val;
	#ifdef __cplusplus
	float16() = default;
	float16(int x) {
		this->val = C_itof16(x);
	}
	float16(unsigned int x) {
		this->val = C_utof16(x);
	}
	float16(float x) {
		this->val = C_ftof16(x);
	}
	float16(long double x) {
		this->val = C_dtof16(x);
	}
	explicit operator bool() const {
		return _iszerof16(this->val);
	}
	explicit operator int() const {
		return C_htoi(this->val);
	}
	explicit operator unsigned int() const {
		return C_htou(this->val);
	}
	explicit operator float() const {
		return C_htof(this->val);
	}
	explicit operator long double() const {
		return C_htod(this->val);
	}
	#endif
} float16;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#ifdef __cplusplus

/* libcalls */

inline float16 operator-(float16 x) {
	float16 ret;
	ret.val = C_hneg(x.val);
	return ret;
}
inline float16 operator+(float16 x, float16 y) {
	float16 ret;
	ret.val = C_hadd(x.val, y.val);
	return ret;
}
inline float16 operator-(float16 x, float16 y) {
	float16 ret;
	ret.val = C_hsub(x.val, y.val);
	return ret;
}
inline float16 operator*(float16 x, float16 y) {
	float16 ret;
	ret.val = C_hmul(x.val, y.val);
	return ret;
}
inline float16 operator/(float16 x, float16 y) {
	float16 ret;
	ret.val = C_hdiv(x.val, y.val);
	return ret;
}

inline float16& operator+=(float16 &x, float16 y) {
	x = x + y;
	return x;
}
inline float16& operator-=(float16 &x, float16 y) {
	x = x - y;
	return x;
}
inline float16& operator*=(float16 &x, float16 y) {
	x = x * y;
	return x;
}
inline float16& operator/=(float16 &x, float16 y) {
	x = x / y;
	return x;
}

inline float16& operator++(float16 &x) {
	float16 value_one;
	value_one.val = 0x3C00;
	x += value_one;
	return x;
}
inline float16 operator++(float16 &x, int) {
	float16 value_one;
	value_one.val = 0x3C00;
	float16 temp = x;
	x = x + value_one;
	return temp;
}
inline float16& operator--(float16 &x) {
	float16 value_one;
	value_one.val = 0x3C00;
	x -= value_one;
	return x;
}
inline float16 operator--(float16 &x, int) {
	float16 value_one;
	value_one.val = 0x3C00;
	float16 temp = x;
	x = x - value_one;
	return temp;
}

inline bool operator==(float16 x, float16 y) {
	return (C_hcmp(x.val, y.val) == 0);
}
inline bool operator!=(float16 x, float16 y) {
	return (C_hcmp(x.val, y.val) != 0);
}
inline bool operator<(float16 x, float16 y) {
	return (C_hcmp(x.val, y.val) < 0);
}
inline bool operator<=(float16 x, float16 y) {
	return (C_hcmp(x.val, y.val) <= 0);
}
inline bool operator>(float16 x, float16 y) {
	return (C_hcmp(x.val, y.val) > 0);
}
inline bool operator>=(float16 x, float16 y) {
	return (C_hcmp(x.val, y.val) >= 0);
}

/* primative functions */

inline float16 fabs(float16 x) {
	float16 ret;
	ret.val = fabsf16(x.val);
	return ret;
}

inline float16 copysign(float16 x, float16 y) {
	float16 ret;
	ret.val = fabsf16(x.val);
	return ret;
}

inline bool signbit(float16 x) {
	return _signbitf16(x.val);
}
inline bool isinf(float16 x) {
	return _isinff16(x.val);
}
inline bool isnan(float16 x) {
	return _isnanf16(x.val);
}
inline bool isnormal(float16 x) {
	return _isnormalf16(x.val);
}
inline bool isfinite(float16 x) {
	return _isfinitef16(x.val);
}
inline bool iszero(float16 x) {
	return _iszerof16(x.val);
}
inline bool issubnormal(float16 x) {
	return _issubnormalf16(x.val);
}
inline int fpclassify(float16 x) {
	return _fpclassifyf16(x.val);
}

inline bool isunordered(float16 x, float16 y) {
	return (_isnanf16(x.val) || _isnanf16(y.val));
}

inline bool islessgreater(float16 x, float16 y) {
	return (x != y) && !(_isnanf16(x.val) || _isnanf16(y.val));
}
inline bool isless(float16 x, float16 y) {
	return (x < y);
}
inline bool islessequal(float16 x, float16 y) {
	return (x <= y);
}
inline bool isgreater(float16 x, float16 y) {
	return (x > y);
}
inline bool isgreaterequal(float16 x, float16 y) {
	return (x >= y);
}

inline float16 fmax(float16 x, float16 y) {
	float16 ret;
	ret.val = fmaxf16(x.val, y.val);
	return ret;
}
inline float16 fmin(float16 x, float16 y) {
	float16 ret;
	ret.val = fmaxf16(x.val, y.val);
	return ret;
}
inline float16 fdim(float16 x, float16 y) {
	float16 ret;
	ret.val = fmaxf16(x.val, y.val);
	return ret;
}

/* manipulation */

inline float16 nextafter(float16 x, float16 y) {
	float16 ret;
	ret.val = nextafterf16(x.val, y.val);
	return ret;
}
inline float16 nextup(float16 x) {
	float16 ret;
	ret.val = nextupf16(x.val);
	return ret;
}
inline float16 nextdown(float16 x) {
	float16 ret;
	ret.val = nextdownf16(x.val);
	return ret;
}
inline float16 nexttoward(float16 x, long double y) {
	float16 ret;
	ret.val = nexttowardf16(x.val, y);
	return ret;
}

inline int ilogb(float16 x) {
	return ilogbf16(x.val);
}
inline float16 frexp(float16 x, int* expon) {
	float16 ret;
	ret.val = frexpf16(x.val, expon);
	return ret;
}
inline float16 ldexp(float16 x, int expon) {
	float16 ret;
	ret.val = ldexpf16(x.val, expon);
	return ret;
}
inline float16 scalbn(float16 x, int expon) {
	float16 ret;
	ret.val = scalbnf16(x.val, expon);
	return ret;
}
inline float16 scalbln(float16 x, long expon) {
	float16 ret;
	ret.val = scalblnf16(x.val, expon);
	return ret;
}

/* rounding */

inline float16 trunc(float16 x) {
	float16 ret;
	ret.val = truncf16(x.val);
	return ret;
}
inline float16 modf(float16 x, float16 *int_part) {
	float16 ret;
	ret.val = modff16(x.val, (__fp16_ABI*)((void*)int_part));
	return ret;
}

inline float16 floor(float16 x) {
	float16 ret;
	ret.val = floorf16(x.val);
	return ret;
}
inline float16 ceil(float16 x) {
	float16 ret;
	ret.val = ceilf16(x.val);
	return ret;
}
inline float16 round(float16 x) {
	float16 ret;
	ret.val = roundf16(x.val);
	return ret;
}
inline float16 roundeven(float16 x) {
	float16 ret;
	ret.val = roundevenf16(x.val);
	return ret;
}
inline float16 nearbyint(float16 x) {
	float16 ret;
	ret.val = nearbyintf16(x.val);
	return ret;
}
inline float16 rint(float16 x) {
	float16 ret;
	ret.val = rintf16(x.val);
	return ret;
}

inline long lround(float16 x) {
	return lroundf16(x.val);
}
inline long lrint(float16 x) {
	return lrintf16(x.val);
}
inline long long llround(float16 x) {
	return llroundf16(x.val);
}
inline long long llrint(float16 x) {
	return llrintf16(x.val);
}

/* remainder */

inline float16 remainder(float16 x, float16 y) {
	float16 ret;
	ret.val = remainderf16(x.val, y.val);
	return ret;
}
inline float16 remquo(float16 x, float16 y, int* int_part) {
	float16 ret;
	ret.val = remquof16(x.val, y.val, int_part);
	return ret;
}

/* exponents and logarithms */

inline float16 exp(float16 x) {
	float16 ret;
	ret.val = expf16(x.val);
	return ret;
}
inline float16 expm1(float16 x) {
	float16 ret;
	ret.val = expm1f16(x.val);
	return ret;
}

inline float16 log(float16 x) {
	float16 ret;
	ret.val = logf16(x.val);
	return ret;
}
inline float16 log1p(float16 x) {
	float16 ret;
	ret.val = log1pf16(x.val);
	return ret;
}

inline float16 pow(float16 x, float16 y) {
	float16 ret;
	ret.val = powf16(x.val, y.val);
	return ret;
}
inline float16 powr(float16 x, float16 y) {
	float16 ret;
	ret.val = powrf16(x.val, y.val);
	return ret;
}

inline float16 hypot(float16 x, float16 y) {
	float16 ret;
	ret.val = hypotf16(x.val, y.val);
	return ret;
}
inline float16 cbrt(float16 x) {
	float16 ret;
	ret.val = cbrtf16(x.val);
	return ret;
}
inline float16 rsqrt(float16 x) {
	float16 ret;
	ret.val = rsqrtf16(x.val);
	return ret;
}

inline float16 exp2(float16 x) {
	float16 ret;
	ret.val = exp2f16(x.val);
	return ret;
}
inline float16 exp10(float16 x) {
	float16 ret;
	ret.val = exp10f16(x.val);
	return ret;
}
inline float16 log2(float16 x) {
	float16 ret;
	ret.val = log2f16(x.val);
	return ret;
}
inline float16 log10(float16 x) {
	float16 ret;
	ret.val = log10f16(x.val);
	return ret;
}
inline float16 logb(float16 x) {
	float16 ret;
	ret.val = logbf16(x.val);
	return ret;
}

/* trigonometry */

inline float16 sin(float16 x) {
	float16 ret;
	ret.val = sinf16(x.val);
	return ret;
}
inline float16 cos(float16 x) {
	float16 ret;
	ret.val = cosf16(x.val);
	return ret;
}
inline float16 tan(float16 x) {
	float16 ret;
	ret.val = tanf16(x.val);
	return ret;
}
inline void sincos(float16 x, float16 *p_sin, float16 *p_cos) {
	sincosf16(x.val, (__fp16_ABI*)((void*)p_sin), (__fp16_ABI*)((void*)p_cos));
}
inline float16 asin(float16 x) {
	float16 ret;
	ret.val = asinf16(x.val);
	return ret;
}
inline float16 acos(float16 x) {
	float16 ret;
	ret.val = acosf16(x.val);
	return ret;
}
inline float16 atan(float16 x) {
	float16 ret;
	ret.val = atanf16(x.val);
	return ret;
}
inline float16 atan2(float16 y, float16 x) {
	float16 ret;
	ret.val = atan2f16(y.val, x.val);
	return ret;
}

/* hyperbolic trigonometry */

inline float16 sinh(float16 x) {
	float16 ret;
	ret.val = sinhf16(x.val);
	return ret;
}
inline float16 cosh(float16 x) {
	float16 ret;
	ret.val = coshf16(x.val);
	return ret;
}
inline float16 tanh(float16 x) {
	float16 ret;
	ret.val = tanhf16(x.val);
	return ret;
}
inline void sinhcosh(float16 x, float16 *p_sinh, float16 *p_cosh) {
	sinhcoshf16(x.val, (__fp16_ABI*)((void*)p_sinh), (__fp16_ABI*)((void*)p_cosh));
}
inline float16 asinh(float16 x) {
	float16 ret;
	ret.val = asinhf16(x.val);
	return ret;
}
inline float16 acosh(float16 x) {
	float16 ret;
	ret.val = acoshf16(x.val);
	return ret;
}
inline float16 atanh(float16 x) {
	float16 ret;
	ret.val = atanhf16(x.val);
	return ret;
}

/* transcendental */

inline float16 lgamma(float16 x) {
	float16 ret;
	ret.val = lgammaf16(x.val);
	return ret;
}
inline float16 tgamma(float16 x) {
	float16 ret;
	ret.val = tgammaf16(x.val);
	return ret;
}
inline float16 erf(float16 x) {
	float16 ret;
	ret.val = erff16(x.val);
	return ret;
}
inline float16 erfc(float16 x) {
	float16 ret;
	ret.val = erfcf16(x.val);
	return ret;
}

#endif /* __cplusplus */

#endif /* FLOAT16_H */
