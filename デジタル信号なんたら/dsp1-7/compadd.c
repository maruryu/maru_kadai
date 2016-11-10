#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	double re;
	double im;
}comp;


comp compAdd(comp in1,comp in2)
{
	comp result;
	
	result.re = in1.re + in2.re;
	result.im = in1.im + in2.im;
	
	return result;
}

comp compDec(comp in1,comp in2)
{
	comp result;
	
	result.re = in1.re - in2.re;
	result.im = in1.im - in2.im;
	
	return result;
}

comp compMulti(comp in1,comp in2)
{
	comp result;
	
	result.re = (in1.re*in2.re) - (in1.im*in2.im);
	result.im = (in1.re*in2.im) + (in1.im*in2.re);
	
	return result;
}

comp compDiv(comp in1,comp in2)
{
	comp result;
	double molecule = pow(in2.re,2) + pow(in2.im,2);

	result.re = ((in1.re*in2.re) + (in1.im*in2.im))/molecule;
	result.im = ((in1.im*in2.re) - (in1.re*in2.im))/molecule;
	
	return result;
}

comp comj(comp in)
{
	comp in;
	
	in.im = -in.im;
	
	return in;
}

int main()
{
	comp result;
	comp xn={1,2};
	comp Xk={3,4};
	result = compAdd(xn,Xk);
	result = compDec(xn,Xk);
	printf("%lf %lf\n",result.re,result.im);
	return 0;
}