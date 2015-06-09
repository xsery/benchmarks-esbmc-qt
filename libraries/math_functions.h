
#include <stddef.h>
#include <stdio.h>
#include <driver_types.h>
#include "definitions.h"
#include <device_functions_decls.h>
#include <intrinsics.h>

#define M_PI     3.14159265358979323846
#define M_PI_2   1.57079632679489661923132169164      // Pi/2
#define NEPERIANO 2.718281828
#define PREC 1e-16

#define __device__ void
#define __host__ void
#define __RETURN_TYPE void
#define __DEVICE_FUNCTIONS_DECL__ void


//###############################################################
// Signature

//Module Single Precision Mathematical Functions
__device__ float 	acosf (float x);
__device__ float 	acoshf (float x);
__device__ float 	asinf (float x);
__device__ float 	asinhf (float x);
__device__ float 	atan2f (float x, float y);
__device__ float 	atanf (float x);
__device__ float 	atanhf (float x);
__device__ float 	cbrtf (float x);
__device__ float 	ceilf (float x);
__device__ float 	copysignf (float x, float y);
__device__ float 	cosf (float x);
__device__ float 	coshf (float x);
__device__ float 	cospif (float x);
__device__ float 	erfcf (float x);
__device__ float 	erfcinvf (float y);
__device__ float 	erfcxf (float x);
__device__ float 	erff (float x);
__device__ float 	erfinvf (float y);
__device__ float 	exp10f (float x);
__device__ float 	exp2f (float x);
__device__ float 	expf (float x);
__device__ float 	expm1f (float x);
__device__ float 	fabsf (float x);
__device__ float 	fdimf (float x, float y);
__device__ float 	fdividef (float x, float y);
__device__ float 	floorf (float x);
__device__ float 	fmaf (float x, float y, float z);
__device__ float 	fmaxf (float x, float y);
__device__ float 	fminf (float x, float y);
__device__ float 	fmodf (float x, float y);
__device__ float 	frexpf (float x, int *nptr);
__device__ float 	hypotf (float x, float y);
__device__ int 	ilogbf (float x);
__device__ int 	isfinite (float a);
__device__ int 	isinf (float a);
__device__ int 	isnan (float a);
__device__ float 	j0f (float x);
__device__ float 	j1f (float x);
__device__ float 	jnf (int n, float x);
__device__ float 	ldexpf (float x, int exp);
__device__ float 	lgammaf (float x);
__device__ long long int 	llrintf (float x);
__device__ long long int 	llroundf (float x);
__device__ float 	log10f (float x);
__device__ float 	log1pf (float x);
__device__ float 	log2f (float x);
__device__ float 	logbf (float x);
__device__ float 	logf (float x);
__device__ long int 	lrintf (float x);
__device__ long int 	lroundf (float x);
__device__ float 	modff (float x, float *iptr);
__device__ float 	nanf (const char *tagp);
__device__ float 	nearbyintf (float x);
__device__ float 	nextafterf (float x, float y);
__device__ float 	powf (float x, float y);
__device__ float 	rcbrtf (float x);
__device__ float 	remainderf (float x, float y);
__device__ float 	remquof (float x, float y, int *quo);
__device__ float 	rintf (float x);
__device__ float 	roundf (float x);
__device__ float 	rsqrtf (float x);
__device__ float 	scalblnf (float x, long int n);
__device__ float 	scalbnf (float x, int n);
__device__ int 	signbit (float a);
__device__ void 	sincosf (float x, float *sptr, float *cptr);
__device__ float 	sinf (float x);
__device__ float 	sinhf (float x);
__device__ float 	sinpif (float x);
__device__ float 	sqrtf (float x);
__device__ float 	tanf (float x);
__device__ float 	tanhf (float x);
__device__ float 	tgammaf (float x);
__device__ float 	truncf (float x);
__device__ float 	y0f (float x);
__device__ float 	y1f (float x);
__device__ float 	ynf (int n, float x);

//Module Double Precision Mathematical Functions
__host__ __device__  double 	acos ( double  x );
__host__ __device__  double 	acosh ( double  x );
__host__ __device__  double 	asin ( double  x );
__host__ __device__  double 	asinh ( double  x );
__host__ __device__  double 	atan ( double  x );
__host__ __device__  double 	atan2 ( double  y, double  x );
__host__ __device__  double 	atanh ( double  x );
__host__ __device__  double 	cbrt ( double  x );
__host__ __device__  double 	ceil ( double  x );
__host__ __device__  double 	copysign ( double  x, double  y );
__host__ __device__  double 	cos ( double  x );
__host__ __device__  double 	cosh ( double  x );
__host__ __device__  double 	cospi ( double  x );
__host__ __device__  double 	cyl_bessel_i0 ( double  x );
__host__ __device__  double 	cyl_bessel_i1 ( double  x );
__host__ __device__  double 	erf ( double  x );
__host__ __device__  double 	erfc ( double  x );
__host__ __device__  double 	erfcinv ( double  y );
__host__ __device__  double 	erfcx ( double  x );
__host__ __device__  double 	erfinv ( double  y );
__host__ __device__  double 	exp ( double  x );
__host__ __device__  double 	exp10 ( double  x );
__host__ __device__  double 	exp2 ( double  x );
__host__ __device__  double 	expm1 ( double  x );
__host__ __device__  double 	fabs ( double  x );
__host__ __device__  double 	fdim ( double  x, double  y );
__host__ __device__  double 	floor ( double  x );
__host__ __device__  double 	fma ( double  x, double  y, double  z );
__host__ __device__  double 	fmax ( double , double );
__host__ __device__  double 	fmin ( double  x, double  y );
__host__ __device__  double 	fmod ( double  x, double  y );
__host__ __device__  double 	frexp ( double  x, int* nptr );
//__host__ __device__  double     CRTDECL 	hypot ( double  x, double  y );
__host__ __device__  int 	ilogb ( double  x );
__host__ __device__ __RETURN_TYPE 	isfinite ( double  a );
__host__ __device__ __RETURN_TYPE 	isinf ( double  a );
__host__ __device__ __RETURN_TYPE 	isnan ( double  a );
__host__ __device__  double 	j0 ( double  x );
__host__ __device__  double 	j1 ( double  x );
__host__ __device__  double 	jn ( int  n, double  x );
__host__ __device__  double 	ldexp ( double  x, int  exp );
__host__ __device__  double 	lgamma ( double  x );
__host__ __device__  long long int 	llrint ( double  x );
__host__ __device__  long long int 	llround ( double  x );
__host__ __device__  double 	log ( double  x );
__host__ __device__  double 	log10 ( double  x );
__host__ __device__  double 	log1p ( double  x );
__host__ __device__  double 	log2 ( double  x );
__host__ __device__  double 	logb ( double  x );
__host__ __device__  long int 	lrint ( double  x );
__host__ __device__  long int 	lround ( double  x );
__host__ __device__  double 	modf ( double  x, double* iptr );
__host__ __device__  double 	nan ( const char* tagp );
__host__ __device__  double 	nearbyint ( double  x );
__host__ __device__  double 	nextafter ( double  x, double  y );
__host__ __device__  double 	norm3d ( double  a, double  b, double  c );
__host__ __device__  double 	norm4d ( double  a, double  b, double  c, double  d );
__host__ __device__  double 	normcdf ( double  y );
__host__ __device__  double 	normcdfinv ( double  y );
__host__ __device__  double 	pow ( double  x, double  y );
__host__ __device__  double 	rcbrt ( double  x );
__host__ __device__  double 	remainder ( double  x, double  y );
__host__ __device__  double 	remquo ( double  x, double  y, int* quo );
__host__ __device__  double 	rhypot ( double  x, double  y );
__host__ __device__  double 	rint ( double  x );
__host__ __device__  double 	rnorm3d ( double  a, double  b, double  c );
__host__ __device__  double 	round ( double  x );
__host__ __device__  double 	rsqrt ( double  x );
__host__ __device__  double 	scalbln ( double  x, long int  n );
__host__ __device__  double 	scalbn ( double  x, int  n );
__host__ __device__  __RETURN_TYPE 	signbit ( double  a );
__host__ __device__ double 	sin ( double  x );
__host__ __device__ void 	sincos ( double  x, double* sptr, double* cptr );
__host__ __device__ void 	sincospi ( double  x, double* sptr, double* cptr );
__host__ __device__ double 	sinh ( double  x );
__host__ __device__ double 	sinpi ( double  x );
__host__ __device__ double 	sqrt ( double  x );
__host__ __device__ double 	tan ( double  x );
__host__ __device__ double 	tanh ( double  x );
__host__ __device__ double 	tgamma ( double  x );
__host__ __device__ double 	trunc ( double  x );
__host__ __device__ double 	y0 ( double  x );
__host__ __device__ double 	y1 ( double  x );
__host__ __device__ double 	yn ( int  n, double  x );


//Module Single Precision Intrinsics
__DEVICE_FUNCTIONS_DECL__ float 	__cosf ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__exp10f ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__expf ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__fadd_rd ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fadd_rn ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fadd_ru ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fadd_rz ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fdiv_rd ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fdiv_rn ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fdiv_ru ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fdiv_rz ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fdividef ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fmaf_rd ( float  x, float  y, float  z );
__DEVICE_FUNCTIONS_DECL__ float 	__fmaf_rn ( float  x, float  y, float  z );
__DEVICE_FUNCTIONS_DECL__ float 	__fmaf_ru ( float  x, float  y, float  z );
__DEVICE_FUNCTIONS_DECL__ float 	__fmaf_rz ( float  x, float  y, float  z );
__DEVICE_FUNCTIONS_DECL__ float 	__fmul_rd ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fmul_rn ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fmul_ru ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fmul_rz ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__frcp_rd ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__frcp_rn ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__frcp_ru ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__frcp_rz ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__frsqrt_rn ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__fsqrt_rd ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__fsqrt_rn ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__fsqrt_ru ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__fsqrt_rz ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__fsub_rd ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fsub_rn ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fsub_ru ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__fsub_rz ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__log10f ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__log2f ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__logf ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__powf ( float  x, float  y );
__DEVICE_FUNCTIONS_DECL__ float 	__saturatef ( float  x );
__DEVICE_FUNCTIONS_DECL__ void 	__sincosf ( float  x, float* sptr, float* cptr );
__DEVICE_FUNCTIONS_DECL__ float 	__sinf ( float  x );
__DEVICE_FUNCTIONS_DECL__ float 	__tanf ( float  x );

//Module Double Precision Intrinsics
__device__  double __ddiv_rd ( double  x, double  y );
__device__  double __ddiv_rn ( double  x, double  y );
__device__  double __ddiv_ru ( double  x, double  y );
__device__  double __ddiv_rz ( double  x, double  y );
__device__  double __drcp_rd ( double  x );
__device__  double __drcp_rn ( double  x );
__device__  double __drcp_ru ( double  x );
__device__  double __drcp_rz ( double  x );
__device__  double __dsqrt_rd ( double  x );
__device__  double __dsqrt_rn ( double  x );
__device__  double __dsqrt_ru ( double  x );
__device__  double __dsqrt_rz ( double  x );


//###############################################################
//Module Single Precision Mathematical Functions

__device__ float 	acosf (float x){

	return 	1/__cosf(x);

}

__device__ float 	acoshf (float x){

	if(x==1)
		return 0;

	return (__powf(NEPERIANO,x) + __powf(NEPERIANO,x*(-1)))*2;

}

__device__ float 	asinf (float x){

	return 1/__sinf(x);

}

__device__ float 	asinhf (float x){

	if(x==0)
		return 1;

	return (__powf(NEPERIANO,x) + __powf(NEPERIANO,x*(-1)))*2;

}

__device__ float 	atan2f (float x, float y){

	float s = x/y;

	return cosf(s)/sinf(s);

}

__device__ float 	atanf (float x){

	__ESBMC_assert((x>1.0) || (x<-1.0), "The number must belong to the interval [-1.0, +1.0]");

	if(x==0)
		return 0;

		return 1/tanf(x);

}

__device__ float 	atanhf (float x){

	float result;

	return result;
}

__device__ float 	cbrtf (float x){

	float result;

	return result;
}

static __forceinline__ float ceilf(float x)
{
  return __nv_ceilf(x);
}

__device__ float 	copysignf (float x, float y){

	if(y<0)
		return x*(-1);
	else
		return x;

}

__device__ float 	cosf (float x){

	return __cosf ( x );

}

__device__ float 	coshf (float x){

	return (powf(NEPERIANO,x) + powf(NEPERIANO,x*(-1)))/2;

}

__device__ float 	cospif (float x){

	float t , s;
    int p;

    x = x*M_PI;

    p = 0;
    s = 1.0;
    t = 1.0;
    x = fmod(x + M_PI, M_PI * 2) - M_PI; // restrict x so that -M_PI < x < M_PI
    double xsqr = x*x;
    double ab = 1;
    while((ab > PREC) && (p < 15))
    {
        p++;
        t = (-t * xsqr) / (((p<<1) - 1) * (p<<1));
        s += t;
        ab = (s==0) ? 1 : fabs(t/s);
    }

	__ESBMC_assert((s >= -1) && (s <= 1), "The number must belong to the interval [-1, +1]");

	return s;
}

__device__ float 	erfcf (float x){

	float result;

	 return result;
}

__device__ float 	erfcinvf (float y){

	float result;

	return result;
}

__device__ float 	erfcxf (float x){

	float result;

	return result;
}

__device__ float 	erff (float x){

	float result;

	return result;
}

__device__ float 	erfinvf (float y){

	float result;

	return result;
}

__device__ float 	exp10f (float x){

	return __exp10f(x);

}

__device__ float 	exp2f (float x){

	return __powf(2,x);

}

__device__ float 	expf (float x){

	return __expf(x);

}

__device__ float 	expm1f (float x){

	return (__expf(x) - 1);

}

__device__ float 	fabsf (float x){

	  return (x < 0) ? -x : x;

}

__device__ float 	fdimf (float x, float y){

	if(x>y)
		return x-y;
	return 0;

}

__device__ float 	fdividef (float x, float y){

	return __fdividef (x,y);

}

__device__ float 	floorf (float x){

	return __logf(1 + x);

}

__device__ float	fmaf (float x, float y, float z){

	__ESBMC_atomic_begin();
	return ((x*y)+z);
	__ESBMC_atomic_end();

}

__device__ float 	fmaxf (float x, float y){

	if(isnan(x)){
		if(isnan(y)){
			nan result;
			return result;
		}
		return y;
	}

	if(isnan(y)){
		return x;
	}

	if(x>y)
		return x;
	else
		return y;

}

__device__ float 	fminf (float x, float y){

	if(isnan(x)){
		if(isnan(y)){
			nan result;
			return result;
		}
		return y;
	}

	if(isnan(y)){
		return x;
	}

	if(x<y)
		return x;
	else
		return y;

}

__device__ float 	fmodf (float x, float y){

	return x - (y * (int)(x/y));

}

__device__ float 	frexpf (float x, int *nptr){

	float result;

	return result;
}

__device__ float 	hypotf (float x, float y){

	float xx = x*x;
	float yy = y*y;
	float aux = xx + yy;

	return __powf(aux,0.5);

}

__device__ int ilogbf (float x){

/*	 __ESBMC_isfinite(x);

	 if(0){
		 return INT_MIN;
	 }else if(isnan(x)){
		 nan result;
		 return result;
	 }else if(isfinite(x)){
		 return INT_MAX;
	 }

	 ilogbf(x) return INT_MIN if the correct value is less than INT_MIN.
*/
	float result;

	return result;

}

__device__ int 	isfinite (float a){

	return __ESBMC_isfinite(a);

}

__device__ int 	isinf (float x){

	return __ESBMC_isinf(x);

}

__device__ int 	isnan (float x){

	return __ESBMC_isnan(x);

}

__device__ float 	j0f (float x){

	float result;

	return result;
}

__device__ float 	j1f (float x){

	float result;

	return result;
}

__device__ float 	jnf (int n, float x){

	float result;

	return result;
}

__device__ float 	ldexpf (float x, int exp){

	return x*__pow(2,exp);

}

__device__ float 	lgammaf (float x){

	float result;

	return result;
}

__device__ long long int 	llrintf (float x){

	float result;

	return result;
}

__device__ long long int 	llroundf (float x){

	float result;

	return result;
}

__device__ float 	log10f (float x){

	return __log10f(x);

}

__device__ float 	log1pf (float x){

	__ESBMC_assert(n < 0, "The number must be greater or equal than 0");
	return	(1+x)*__logf(NEPERIANO);

}

float log2f(float n){

	return	__log2f(x);

}

__device__ float 	logbf (float x){

	float result;

	return result;
}

__device__ float 	logf (float x){

	return __logf(x);

}

__device__ long int 	lrintf (float x){

	float result;

	return result;
}

__device__ long int 	lroundf (float x){

	float result;

	return result;
}

__device__ float 	modff (float x, float *iptr){

	float result;

	return result;
}

__device__ float 	nanf (const char *tagp){

	float result;

	return result;
}

__device__ float 	nearbyintf (float x){

	float result;

	return result;
}

__device__ float 	nextafterf (float x, float y){

	float result;

	return result;
}

__device__ float 	powf (float a, float b){

	return __powf ( a , b );

}

__device__ float 	rcbrtf (float x){

	return __powf(x,(1/3));

}

__device__ float 	remainderf (float x, float y){

	float result;

	return result;
}

__device__ float 	remquof (float x, float y, int *quo){

	float result;

	return result;
}

__device__  float rhypotf ( float  x, float  y ){

		return 1/hypotf( x , y );

}

__device__ float 	rintf (float x){

	double rcp = x;
	double reference = (int)rcp + 0.5;

	if(rcp < reference )
		return (int)rcp;
	else
		return (int)rcp + 1;

}

__device__ float 	roundf (float x){

	float result;

	return result;
}

__device__ float 	rsqrtf (float x){

	__ESBMC_assert(x == 0 , "Value must be nonzero");

	return (1/sqrtf(x));

}

__device__ float 	scalblnf (float x, long int n){

	float result;

	return result;
}

__device__ float 	scalbnf (float x, int n){

	float result;

	return result;
}

__device__ int 	signbit (float a){

	float result;

	return result;
}

__device__ void 	sincosf (float x, float *sptr, float *cptr){

	float result;

}

__device__ float 	sinf (float x){

	return __sinf( x );

}

__device__ float 	sinhf (float x){

	return (powf(NEPERIANO,x) - powf(NEPERIANO,x*(-1)))/2;

}

__device__ float 	sinpif (float x){

	return cos((x-M_PI_2)*M_PI);

}

__device__ float 	sqrtf (float n){

	  /*We are using n itself as initial approximation
	   This can definitely be improved */
	  float x = n;
	  float y = 1;
	  //float e = 0.000001; /* e decides the accuracy level*/
	  //double e = 1e-16;
	  float e = 1;
	  int i = 0;
	//  while(fabs(x - y) > e)
	  while(i++ < 15) //Change this line to increase precision
	  {
	    x = (x + y)/2.0;
	    y = n/x;
	  }
	  return x;

}

__device__ float 	tanf (float x){

	return __tanf(x);

}

__device__ float 	tanhf (float x){

	float result;

	return result;
}

__device__ float 	tgammaf (float x){

	float result;

	return result;
}

__device__ float 	truncf (float x){

	float result;

	return result;
}

__device__ float 	y0f (float x){

	float result;

	return result;
}

__device__ float 	y1f (float x){

	float result;

	return result;
}

__device__ float 	ynf (int n, float x){

	float result;

	return result;
}

//###############################################################
//Module Double Precision Mathematical Functions
/*
__host__ __device__ double 	acos ( double  x )
__host__ ​ __device__ ​ double 	acosh ( double  x )
__host__ ​ __device__ ​ double 	asin ( double  x )
__host__ ​ __device__ ​ double 	asinh ( double  x )
__host__ ​ __device__ ​ double 	atan ( double  x )
__host__ ​ __device__ ​ double 	atan2 ( double  y, double  x )
__host__ ​ __device__ ​ double 	atanh ( double  x )
__host__ ​ __device__ ​ double 	cbrt ( double  x )
__host__ ​ __device__ ​ double 	ceil ( double  x )
__host__ ​ __device__ ​ double 	copysign ( double  x, double  y )
__host__ ​ __device__ ​ double 	cos ( double  x )
__host__ ​ __device__ ​ double 	cosh ( double  x )
__host__ ​ __device__ ​ double 	cospi ( double  x )
__host__ ​ __device__ ​ double 	cyl_bessel_i0 ( double  x )
__host__ ​ __device__ ​ double 	cyl_bessel_i1 ( double  x )
__host__ ​ __device__ ​ double 	erf ( double  x )
__host__ ​ __device__ ​ double 	erfc ( double  x )
__host__ ​ __device__ ​ double 	erfcinv ( double  y )
__host__ ​ __device__ ​ double 	erfcx ( double  x )
__host__ ​ __device__ ​ double 	erfinv ( double  y )
__host__ ​ __device__ ​ double 	exp ( double  x )
__host__ ​ __device__ ​ double 	exp10 ( double  x )
__host__ ​ __device__ ​ double 	exp2 ( double  x )
__host__ ​ __device__ ​ double 	expm1 ( double  x )
__host__ ​ __device__ ​ double 	fabs ( double  x )
__host__ ​ __device__ ​ double 	fdim ( double  x, double  y )
__host__ ​ __device__ ​ double 	floor ( double  x )
__host__ ​ __device__ ​ double 	fma ( double  x, double  y, double  z )
__host__ ​ __device__ ​ double 	fmax ( double , double )
__host__ ​ __device__ ​ double 	fmin ( double  x, double  y )
__host__ ​ __device__ ​ double 	fmod ( double  x, double  y )
__host__ ​ __device__ ​ double 	frexp ( double  x, int* nptr )
__host__ ​ __device__ ​ double __CRTDECL 	hypot ( double  x, double  y )
__host__ ​ __device__ ​ int 	ilogb ( double  x )
__host__ ​ __device__ ​ __RETURN_TYPE 	isfinite ( double  a )
__host__ ​ __device__ ​ __RETURN_TYPE 	isinf ( double  a )
__host__ ​ __device__ ​ __RETURN_TYPE 	isnan ( double  a )
__host__ ​ __device__ ​ double 	j0 ( double  x )
__host__ ​ __device__ ​ double 	j1 ( double  x )
__host__ ​ __device__ ​ double 	jn ( int  n, double  x )
__host__ ​ __device__ ​ double 	ldexp ( double  x, int  exp )
__host__ ​ __device__ ​ double 	lgamma ( double  x )
__host__ ​ __device__ ​ long long int 	llrint ( double  x )
__host__ ​ __device__ ​ long long int 	llround ( double  x )
__host__ ​ __device__ ​ double 	log ( double  x )
__host__ ​ __device__ ​ double 	log10 ( double  x )
__host__ ​ __device__ ​ double 	log1p ( double  x )
__host__ ​ __device__ ​ double 	log2 ( double  x )
__host__ ​ __device__ ​ double 	logb ( double  x )
__host__ ​ __device__ ​ long int 	lrint ( double  x )
__host__ ​ __device__ ​ long int 	lround ( double  x )
__host__ ​ __device__ ​ double 	modf ( double  x, double* iptr )
__host__ ​ __device__ ​ double 	nan ( const char* tagp )
__host__ ​ __device__ ​ double 	nearbyint ( double  x )
__host__ ​ __device__ ​ double 	nextafter ( double  x, double  y )
__host__ ​ __device__ ​ double 	norm3d ( double  a, double  b, double  c )
__host__ ​ __device__ ​ double 	norm4d ( double  a, double  b, double  c, double  d )
__host__ ​ __device__ ​ double 	normcdf ( double  y )
__host__ ​ __device__ ​ double 	normcdfinv ( double  y )
__host__ ​ __device__ ​ double 	pow ( double  x, double  y )
__host__ ​ __device__ ​ double 	rcbrt ( double  x )
__host__ ​ __device__ ​ double 	remainder ( double  x, double  y )
__host__ ​ __device__ ​ double 	remquo ( double  x, double  y, int* quo )
__host__ ​ __device__ ​ double 	rhypot ( double  x, double  y )
__host__ ​ __device__ ​ double 	rint ( double  x )
__host__ ​ __device__ ​ double 	rnorm3d ( double  a, double  b, double  c )
__host__ ​ __device__ ​ double 	round ( double  x )
__host__ ​ __device__ ​ double 	rsqrt ( double  x )
__host__ ​ __device__ ​ double 	scalbln ( double  x, long int  n )
__host__ ​ __device__ ​ double 	scalbn ( double  x, int  n )
__host__ ​ __device__ ​ __RETURN_TYPE 	signbit ( double  a )
__host__ ​ __device__ ​ double 	sin ( double  x )
__host__ ​ __device__ ​ void 	sincos ( double  x, double* sptr, double* cptr )
__host__ ​ __device__ ​ void 	sincospi ( double  x, double* sptr, double* cptr )
__host__ ​ __device__ ​ double 	sinh ( double  x )
__host__ ​ __device__ ​ double 	sinpi ( double  x )
__host__ ​ __device__ ​ double 	sqrt ( double  x )
__host__ ​ __device__ ​ double 	tan ( double  x )
__host__ ​ __device__ ​ double 	tanh ( double  x )
__host__ ​ __device__ ​ double 	tgamma ( double  x )
__host__ ​ __device__ ​ double 	trunc ( double  x )
__host__ ​ __device__ ​ double 	y0 ( double  x )
__host__ ​ __device__ ​ double 	y1 ( double  x )
__host__ ​ __device__ ​ double 	yn ( int  n, double  x )
*/

//###############################################################
//Module Single Precision Intrinsics

__DEVICE_FUNCTIONS_DECL__ float 	__cosf ( float  x ){

	float t , s;
    int p;
    p = 0;
    s = 1.0;
    t = 1.0;
    x = fmodf(x + M_PI, M_PI * 2) - M_PI; // restrict x so that -M_PI < x < M_PI
    double xsqr = x*x;
    double ab = 1;
    while((ab > PREC) && (p < 15))
    {
        p++;
        t = (-t * xsqr) / (((p<<1) - 1) * (p<<1));
        s += t;
        ab = (s==0) ? 1 : fabsf(t/s);
    }

	__ESBMC_assert((s < -1) || (s > 1), "The number must belong to the interval [-1, +1]");

	return s;

}

__DEVICE_FUNCTIONS_DECL__ float 	__exp10f ( float  x ){

	return __powf(10,x);

}

__DEVICE_FUNCTIONS_DECL__ float 	__expf ( float  x ){

	return __powf(NEPERIANO,x);

}

__DEVICE_FUNCTIONS_DECL__ float 	__fadd_rd ( float  x, float  y ){

	return  (int)(x+y);

}

__DEVICE_FUNCTIONS_DECL__ float 	__fadd_rn ( float  x, float  y ){

	float sum = (x+y);
	float reference = (int)sum + 0.5;

	if(sum < reference )
		return (int)sum;
	else
		return (int)sum + 1;
}

__DEVICE_FUNCTIONS_DECL__ float 	__fadd_ru ( float  x, float  y ){

	float sum = (int)(x+y);

	if(((x+y) - sum) == 0)
		return sum;
	else
		return sum + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fadd_rz ( float  x, float  y ){

	return  (int)(x+y);

}

__DEVICE_FUNCTIONS_DECL__ float 	__fdiv_rd ( float  x, float  y ){

	return  (int)(x/y);

}

__DEVICE_FUNCTIONS_DECL__ float 	__fdiv_rn ( float  x, float  y ){

	float div = (x/y);
	float reference = (int)div + 0.5;

	if(div < reference )
		return (int)div;
	else
		return (int)div + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fdiv_ru ( float  x, float  y ){

	float div = (int)(x/y);

	if(((x/y) - div) == 0)
		return div;
	else
		return div + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fdiv_rz ( float  x, float  y ){

	return  (int)(x/y);

}

__DEVICE_FUNCTIONS_DECL__ float 	__fdividef ( float  x, float  y ){

	return x/y;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fmaf_rd ( float  x, float  y, float  z ){

	__ESBMC_atomic_begin();
	return (int)((x*y)+z);
	__ESBMC_atomic_end();

}

__DEVICE_FUNCTIONS_DECL__ float 	__fmaf_rn ( float  x, float  y, float  z ){

	__ESBMC_atomic_begin();
	float fma = ((x*y)+z);
	float reference = (int)fma + 0.5;

	if(fma < reference )
		return (int)fma;
	else
		return (int)fma + 1;
	__ESBMC_atomic_end();

}

__DEVICE_FUNCTIONS_DECL__ float 	__fmaf_ru ( float  x, float  y, float  z ){

	__ESBMC_atomic_begin();
	float fma = (int)((x*y)+z);

	if(((x/y) - fma) == 0)
		return fma;
	else
		return fma + 1;
	__ESBMC_atomic_end();

}

__DEVICE_FUNCTIONS_DECL__ float 	__fmaf_rz ( float  x, float  y, float  z ){

	__ESBMC_atomic_begin();
	return (int)((x*y)+z);
	__ESBMC_atomic_end();

}

__DEVICE_FUNCTIONS_DECL__ float 	__fmul_rd ( float  x, float  y ){

	return (int)(x*y);

}

__DEVICE_FUNCTIONS_DECL__ float 	__fmul_rn ( float  x, float  y ){

	float mul = (x*y);
	float reference = (int)mul + 0.5;

	if(mul < reference )
		return (int)mul;
	else
		return (int)mul + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fmul_ru ( float  x, float  y ){

	float mul = (int)(x*y);

	if(((x*y) - mul) == 0)
		return mul;
	else
		return mul + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fmul_rz ( float  x, float  y ){

	return (int)(x*y);

}

__DEVICE_FUNCTIONS_DECL__ float 	__frcp_rd ( float  x ){

	return (int)(1/x);

}

__DEVICE_FUNCTIONS_DECL__ float 	__frcp_rn ( float  x ){

	float frcp = (1/x);
	float reference = (int)frcp + 0.5;

	if(frcp < reference )
		return (int)frcp;
	else
		return (int)frcp + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__frcp_ru ( float  x ){

	float frcp = (int)(1/x);

	if(((1/x) - frcp) == 0)
		return frcp;
	else
		return frcp + 1;
}

__DEVICE_FUNCTIONS_DECL__ float 	__frcp_rz ( float  x ){

	return (int)(1/x);

}

__DEVICE_FUNCTIONS_DECL__ float 	__frsqrt_rn ( float  n ){

	/*We are using n itself as initial approximation
 	 This can definitely be improved */
	float x = n;
	float y = 1;
	//float e = 0.000001; /* e decides the accuracy level*/
	//double e = 1e-16;
	float e = 1;
	int i = 0;
	//  while(fabs(x - y) > e)
	while(i++ < 15) //Change this line to increase precision
	{
		x = (x + y)/2.0;
		y = n/x;
	}

	float invSqrt = (1/x);
	float reference = (int)invSqrt + 0.5;

	if(invSqrt < reference )
		return (int)invSqrt;
	else
		return (int)invSqrt + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fsqrt_rd ( float  n ){

	  /*We are using n itself as initial approximation
	   This can definitely be improved */
	  float x = n;
	  float y = 1;
	  //float e = 0.000001; /* e decides the accuracy level*/
	  //double e = 1e-16;
	  float e = 1;
	  int i = 0;
	//  while(fabs(x - y) > e)
	  while(i++ < 15) //Change this line to increase precision
	  {
	    x = (x + y)/2.0;
	    y = n/x;
	  }

	  return (int)(x);

}

__DEVICE_FUNCTIONS_DECL__ float 	__fsqrt_rn ( float  n ){

	  /*We are using n itself as initial approximation
	   This can definitely be improved */
	  float x = n;
	  float y = 1;
	  //float e = 0.000001; /* e decides the accuracy level*/
	  //double e = 1e-16;
	  float e = 1;
	  int i = 0;
	//  while(fabs(x - y) > e)
	  while(i++ < 15) //Change this line to increase precision
	  {
	    x = (x + y)/2.0;
	    y = n/x;
	  }

	  float sqrt = x;
	  float reference = (int)sqrt + 0.5;

		if(sqrt < reference )
			return (int)sqrt;
		else
			return (int)sqrt + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fsqrt_ru ( float  n ){

	  /*We are using n itself as initial approximation
	   This can definitely be improved */
	  float x = n;
	  float y = 1;
	  //float e = 0.000001; /* e decides the accuracy level*/
	  //double e = 1e-16;
	  float e = 1;
	  int i = 0;
	//  while(fabs(x - y) > e)
	  while(i++ < 15) //Change this line to increase precision
	  {
	    x = (x + y)/2.0;
	    y = n/x;
	  }

	  float sqrt = (int)(x);

	  if(((1/x) - sqrt) == 0)
		  return sqrt;
	  else
		  return sqrt + 1;

}


__DEVICE_FUNCTIONS_DECL__ float 	__fsqrt_rz ( float  n ){

	  /*We are using n itself as initial approximation
	   This can definitely be improved */
	  float x = n;
	  float y = 1;
	  //float e = 0.000001; /* e decides the accuracy level*/
	  //double e = 1e-16;
	  float e = 1;
	  int i = 0;
	//  while(fabs(x - y) > e)
	  while(i++ < 15) //Change this line to increase precision
	  {
	    x = (x + y)/2.0;
	    y = n/x;
	  }

	  return (int)(x);

}

__DEVICE_FUNCTIONS_DECL__ float 	__fsub_rd ( float  x, float  y ){

	return (int)(x-y);

}

__DEVICE_FUNCTIONS_DECL__ float 	__fsub_rn ( float  x, float  y ){

	float sub = (x-y);
	float reference = (int)sub + 0.5;

	if(sub < reference )
		return (int)sub;
	else
		return (int)sub + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fsub_ru ( float  x, float  y ){

	float sub = (int)(x-y);

	if(((x-y) - sub) == 0)
		return sub;
	else
		return sub + 1;

}

__DEVICE_FUNCTIONS_DECL__ float 	__fsub_rz ( float  x, float  y ){

	return (int)(x-y);

}

__DEVICE_FUNCTIONS_DECL__ float 	__log10f ( float  x ){

	__ESBMC_assert(n < 0, "The number must be greater or equal than 0");
	return	x*logf(10);

}

__DEVICE_FUNCTIONS_DECL__ float 	__log2f ( float  x ){

	__ESBMC_assert(n < 0, "The number must be greater or equal than 0");
	return	x*__logf(2);

}

__DEVICE_FUNCTIONS_DECL__ float 	__logf ( float  x ){

	__ESBMC_assert(n < 0, "The number must be greater or equal than 0");

	int i;
	float r=0;

	for(i=0;i<15;i++){
		float pA = powf((x-1)/(x+1),((2*i)+1));
		float pB = (1/((2*i) + 1));
		r = r + pA*pB;
	}

	return r*2;

}

float 	__powf ( float  x, float  y ){
	   int result = 1;

	   if (y == 0)
		   return result;

	   if (y < 0)
		   return 1 / pow(x, -y);

	   float temp = pow(x, y / 2);
	   if ((int)y % 2 == 0)
	      return temp * temp;
	   else
	      return (x * temp * temp);
}


__DEVICE_FUNCTIONS_DECL__ float __saturatef ( float  x ){

	if(x < 0)
		return 0;

	if(x > 1)
		return 1.0;

	if( (x>=0) || (x<=1) )
		return x;

	if(isnan(x))
		return 0.0;

}


__DEVICE_FUNCTIONS_DECL__ void 	__sincosf ( float  x, float* sptr, float* cptr );



__DEVICE_FUNCTIONS_DECL__ float 	__sinf ( float  x ){

	return __cos(x-M_PI_2);

}

__DEVICE_FUNCTIONS_DECL__ float 	__tanf ( float  x ){

	if(x==0)
		return 0;

	return __sinf(x)/__cosf(x);

}

//###############################################################
//Module Double Precision Intrinsics

__device__  double __ddiv_rd ( double  x, double  y ){

	return  (int)(x/y);

}

__device__  double __ddiv_rn ( double  x, double  y ){

	double div = (x/y);
	double reference = (int)div + 0.5;

	if(div < reference )
		return (int)div;
	else
		return (int)div + 1;

}

__device__  double __ddiv_ru ( double  x, double  y ){

	double div = (int)(x/y);

	if(((x/y) - div) == 0)
		return div;
	else
		return div + 1;

}

__device__  double __ddiv_rz ( double  x, double  y ){

	return  (int)(x/y);

}

__device__  double __drcp_rd ( double  x ){

	return (int)(1/x);

}

__device__  double __drcp_rn ( double  x ){

	double rcp = (1/x);
	double reference = (int)rcp + 0.5;

	if(rcp < reference )
		return (int)rcp;
	else
		return (int)rcp + 1;

}

__device__  double __drcp_ru ( double  x ){


	double rcp = (int)(1/x);

	if(((1/x) - rcp) == 0)
		return rcp;
	else
		return rcp + 1;

}

__device__  double __drcp_rz ( double  x ){

	return (int)(1/x);

}

__device__  double __dsqrt_rd ( double  n ){

	  /*We are using n itself as initial approximation
	   This can definitely be improved */
	  double x = n;
	  double y = 1;
	  //float e = 0.000001; /* e decides the accuracy level*/
	  //double e = 1e-16;
	  double e = 1;
	  int i = 0;
	//  while(fabs(x - y) > e)
	  while(i++ < 15) //Change this line to increase precision
	  {
	    x = (x + y)/2.0;
	    y = n/x;
	  }

	  return (int)(x);

}

__device__  double __dsqrt_rn ( double  n ){


	  /*We are using n itself as initial approximation
	   This can definitely be improved */
	  double x = n;
	  double y = 1;
	  //float e = 0.000001; /* e decides the accuracy level*/
	  //double e = 1e-16;
	  double e = 1;
	  int i = 0;
	//  while(fabs(x - y) > e)
	  while(i++ < 15) //Change this line to increase precision
	  {
	    x = (x + y)/2.0;
	    y = n/x;
	  }

	  double sqrt = x;
	  double reference = (int)sqrt + 0.5;

		if(sqrt < reference )
			return (int)sqrt;
		else
			return (int)sqrt + 1;

}

__device__  double __dsqrt_ru ( double  n ){

	  /*We are using n itself as initial approximation
	   This can definitely be improved */
	  double x = n;
	  double y = 1;
	  //float e = 0.000001; /* e decides the accuracy level*/
	  //double e = 1e-16;
	  double e = 1;
	  int i = 0;
	//  while(fabs(x - y) > e)
	  while(i++ < 15) //Change this line to increase precision
	  {
	    x = (x + y)/2.0;
	    y = n/x;
	  }

	  double sqrt = (int)(x);

	  if(((1/x) - sqrt) == 0)
		  return sqrt;
	  else
		  return sqrt + 1;

}

__device__  double __dsqrt_rz ( double  n ){

	  /*We are using n itself as initial approximation
	   This can definitely be improved */
	  double x = n;
	  double y = 1;
	  //float e = 0.000001; /* e decides the accuracy level*/
	  //double e = 1e-16;
	  double e = 1;
	  int i = 0;
	//  while(fabs(x - y) > e)
	  while(i++ < 15) //Change this line to increase precision
	  {
	    x = (x + y)/2.0;
	    y = n/x;
	  }

	  return (int)(x);

}

//###############################################################
//Module Integer Intrinsics

__DEVICE_FUNCTIONS_DECL__ unsigned int 	__brev ( unsigned int  x );
__DEVICE_FUNCTIONS_DECL__ unsigned long long int 	__brevll ( unsigned long long int x );
__DEVICE_FUNCTIONS_DECL__ unsigned int 	__byte_perm ( unsigned int  x, unsigned int  y, unsigned int  s );
__DEVICE_FUNCTIONS_DECL__ int 	__clz ( int  x );
__DEVICE_FUNCTIONS_DECL__ int 	__clzll ( long long int x );
__DEVICE_FUNCTIONS_DECL__ int 	__ffs ( int  x );
__DEVICE_FUNCTIONS_DECL__ int 	__ffsll ( long long int x );
__DEVICE_FUNCTIONS_DECL__ int 	__hadd ( int , int );
__DEVICE_FUNCTIONS_DECL__ int 	__mul24 ( int  x, int  y );
__DEVICE_FUNCTIONS_DECL__ long long int 	__mul64hi ( long long int x, long long int y );
__DEVICE_FUNCTIONS_DECL__ int 	__mulhi ( int  x, int  y );
__DEVICE_FUNCTIONS_DECL__ int 	__popc ( unsigned int  x );
__DEVICE_FUNCTIONS_DECL__ int 	__popcll ( unsigned long long int x );
__DEVICE_FUNCTIONS_DECL__ int 	__rhadd ( int , int );
__DEVICE_FUNCTIONS_DECL__ unsigned int 	__sad ( int  x, int  y, unsigned int  z );
__DEVICE_FUNCTIONS_DECL__ unsigned int 	__uhadd ( unsigned int, unsigned int );
__DEVICE_FUNCTIONS_DECL__ unsigned int 	__umul24 ( unsigned int  x, unsigned int  y );
__DEVICE_FUNCTIONS_DECL__ unsigned long long int 	__umul64hi ( unsigned long long int x, unsigned long long int y );
__DEVICE_FUNCTIONS_DECL__ unsigned int 	__umulhi ( unsigned int  x, unsigned int  y );
__DEVICE_FUNCTIONS_DECL__ unsigned int 	__urhadd ( unsigned int, unsigned int );
__DEVICE_FUNCTIONS_DECL__ unsigned int 	__usad ( unsigned int  x, unsigned int  y, unsigned int  z );


//###############################################################
//Module Type Casting Intrinsics

__DEVICE_FUNCTIONS_DECL__ int __double2int_rz ( double );
__DEVICE_FUNCTIONS_DECL__ long long int __double2ll_rz ( double );
__DEVICE_FUNCTIONS_DECL__ unsigned int __double2uint_rz ( double );
__DEVICE_FUNCTIONS_DECL__ unsigned long long int __double2ull_rz ( double );
__DEVICE_FUNCTIONS_DECL__ unsigned short __float2half_rn ( float  x );
__DEVICE_FUNCTIONS_DECL__ int __float2int_rd ( float  x );
__DEVICE_FUNCTIONS_DECL__ int __float2int_rn ( float  x );
__DEVICE_FUNCTIONS_DECL__ int __float2int_ru ( float );
__DEVICE_FUNCTIONS_DECL__ int __float2int_rz ( float  x );
__DEVICE_FUNCTIONS_DECL__ long long int __float2ll_rd ( float  x );
__DEVICE_FUNCTIONS_DECL__ long long int __float2ll_rn ( float  x );
__DEVICE_FUNCTIONS_DECL__ long long int __float2ll_ru ( float  x );
__DEVICE_FUNCTIONS_DECL__ long long int __float2ll_rz ( float  x );
__DEVICE_FUNCTIONS_DECL__ unsigned int __float2uint_rd ( float  x );
__DEVICE_FUNCTIONS_DECL__ unsigned int __float2uint_rn ( float  x );
__DEVICE_FUNCTIONS_DECL__ unsigned int __float2uint_ru ( float  x );
__DEVICE_FUNCTIONS_DECL__ unsigned int __float2uint_rz ( float  x );
__DEVICE_FUNCTIONS_DECL__ unsigned long long int __float2ull_rd ( float  x );
__DEVICE_FUNCTIONS_DECL__ unsigned long long int __float2ull_rn ( float  x );
__DEVICE_FUNCTIONS_DECL__ unsigned long long int __float2ull_ru ( float  x );
__DEVICE_FUNCTIONS_DECL__ unsigned long long int __float2ull_rz ( float  x );
__DEVICE_FUNCTIONS_DECL__ int __float_as_int ( float  x );
__DEVICE_FUNCTIONS_DECL__ float __half2float ( unsigned short x );
__DEVICE_FUNCTIONS_DECL__ float __int2float_rd ( int  x );
__DEVICE_FUNCTIONS_DECL__ float __int2float_rn ( int  x );
__DEVICE_FUNCTIONS_DECL__ float __int2float_ru ( int  x );
__DEVICE_FUNCTIONS_DECL__ float __int2float_rz ( int  x );
__DEVICE_FUNCTIONS_DECL__ float __int_as_float ( int  x );
__DEVICE_FUNCTIONS_DECL__ float __ll2float_rd ( long long int x );
__DEVICE_FUNCTIONS_DECL__ float __ll2float_rn ( long long int x );
__DEVICE_FUNCTIONS_DECL__ float __ll2float_ru ( long long int x );
__DEVICE_FUNCTIONS_DECL__ float __ll2float_rz ( long long int x );
__DEVICE_FUNCTIONS_DECL__ float __uint2float_rd ( unsigned int  x );
__DEVICE_FUNCTIONS_DECL__ float __uint2float_rn ( unsigned int  x );
__DEVICE_FUNCTIONS_DECL__ float __uint2float_ru ( unsigned int  x );
__DEVICE_FUNCTIONS_DECL__ float __uint2float_rz ( unsigned int  x );
__DEVICE_FUNCTIONS_DECL__ float __ull2float_rd ( unsigned long long int x );
__DEVICE_FUNCTIONS_DECL__ float __ull2float_rn ( unsigned long long int x );
__DEVICE_FUNCTIONS_DECL__ float __ull2float_ru ( unsigned long long int x );
__DEVICE_FUNCTIONS_DECL__ float __ull2float_rz ( unsigned long long int x );

