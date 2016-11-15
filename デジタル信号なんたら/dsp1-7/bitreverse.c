#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	double re;
	double im;
}comp;

void bitRev(int *bit,int N)
{
	int b=log2(N);
	int i,j,bn=1;
	bit[0]=0;
	for(i=0;i<b;i++){
		for(j=0;j<bn;j++){
			bit[j+bn]=bit[j]+N/(bn*2);
			//bit[(j+1)+N/2]=bit[j+1]+1;
		}
		bn*=2;
	}
}

int main()
{
	int i,N=8;
	int result[8];
	bitRev(result,N);
	for(i=0;i<N;i++){
		printf("%d\n",result[i]);
	}
	return 0;
}