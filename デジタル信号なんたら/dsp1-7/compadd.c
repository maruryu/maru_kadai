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
	
	in.im = -in.im;
	
	return in;
}

void twid(comp *wnk,int N)
{
	double e=(2*M_PI/N);
	int i;
	for(i=0;i<N/2;i++){
		wnk[i].re = cos(e*i);
		wnk[i].im = sin(e*i);
	}
}

int main()
{
	comp result[8];
	comp xn={1,2};
	comp Xk={3,4};
	twid(result,8);
	int i;
	for(i=0;i<8;i++){
		printf("%lf %lf\n",result[i].re,result[i].im);
	}
	return 0;
}