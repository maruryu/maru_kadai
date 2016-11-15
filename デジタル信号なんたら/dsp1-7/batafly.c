#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	double re;
	double im;
}comp;

#define N 8

void bitRev(int *bit)
{
	int b=log2(N);
	int i,j,bn=1;
	bit[0]=0;
	for(i=0;i<b;i++){
		for(j=0;j<bn;j++){
			bit[j+bn]=bit[j]+N/(bn*2);
		}
		bn*=2;
	}
}

void contentsChange(int *xn,int *bit)
{
	int i;
	int xcpy[N];
	memcpy(xcpy,xn,sizeof(int)*N);
	for(i=0;i<N;i++){
		xn[i]=xcpy[bit[i]];
	}
}

void batCulc(int *xn)
{
	int i,j,y;
	for(i=0;i<3;i++){
		for(j=0;j<(N/(pow(2,i+1)));j++){
			
		}
	}
}

void twid(comp *wnk,int n)
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
	int i;
	int result[8]={0,1,2,3,4,5,6,7};
	int bit_r[8];
	bitRev(bit_r);
	contentsChange(result,bit_r);
	for(i=0;i<N;i++){
		printf("%d\n",result[i]);
	}
	return 0;
}