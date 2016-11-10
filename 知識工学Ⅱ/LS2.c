#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MT.h"
#define MAX 20000000

double rv[MAX][4]={0};

double rv_A = 0.2;
double rv_B = 0.85;
double rv_C[2][2] ={{0.1,0.75},{0.3,0.95}};
double rv_D[2]={0.95,0.8};

double probability[4]={0.2,0.85,0.3575,0.853625};

void RandomGenerate()
{
	long i;
	int j;
	init_genrand((unsigned)time(NULL));
	for(i=0;i<MAX;i++){
		for(j=0;j<4;j++){
			rv[i][j]=genrand_real3();
		}
	}
}

void Change()
{
	long i;
	int j;
	for(i=0;i<MAX;i++){
		if(rv[i][0]<=rv_A){
			rv[i][0]=0;
		}else{
			rv[i][0]=1;
		}
		
		if(rv[i][1]<=rv_B){
			rv[i][1]=0;
		}else{
			rv[i][1]=1;
		}
		if(rv[i][2]<=rv_C[(int)rv[i][0]][(int)rv[i][1]]){
			rv[i][2]=0;
		}else{
			rv[i][2]=1;
		}
		if(rv[i][3]<=rv_D[(int)rv[i][2]]){
			rv[i][3]=0;
		}else{
			rv[i][3]=1;
		}
	}
}

int Norm()
{
	long i=0,countA=0,countB=0,countC=0,countD=0;
	printf("c\n");
	while(i<MAX){
		if(rv[i][0]==0) countA++;
		if(rv[i][1]==0) countB++;
		if(rv[i][2]==0) countC++;
		if(rv[i][3]==0) countD++;
		
		double A=probability[0]-((double)countA/(double)(i+1));
		double B=probability[1]-((double)countB/(double)(i+1));
		double C=probability[2]-((double)countC/(double)(i+1));
		double D=probability[3]-((double)countD/(double)(i+1));
		if(A<0.0003 || A<(-0.0003)){
			if(B<0.0003 || B<(-0.0003)){
				if(C<0.0003 || C<(-0.0003)){
					if(D<0.0003 || D<(-0.0003)){
						break;
					}
				}
			}
		}
		i++;
	}
	printf("a");
	return i;
}


int main()
{
	long i;
	RandomGenerate();
	Change();
	i=Norm();
	printf("b");
	printf("%d",i);
	return 0;
}