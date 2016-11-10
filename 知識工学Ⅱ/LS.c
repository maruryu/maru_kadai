/*31番　丸龍之介　生成するサンプル数はこれから決めます
MT.hはメルセンス・ツイスタを用いて乱数を生成するヘッダーファイルです．*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MT.h"
#define MAX 16000000
#define Number 3000

double rv[MAX][4]={0};

double rv_A = 0.2;
double rv_B = 0.85;
double rv_C[2][2] ={{0.1,0.75},{0.3,0.95}};
double rv_D[2]={0.95,0.8};

int input[2][4]={0};

int save[8]={0};
int save1[8]={0};

double probability[4]={0.2,0.85,0.3575,0.853625};


double Q1(long N)
{
	int count1=0,count2=0;
	long i;
	for(i=0;i<N;i++){
		if(rv[i][1]==1) count1++;
		if(rv[i][1]==1 && rv[i][3]==1){
			count2++;
		}
	}
	return (double)count2/(double)count1;
}

double Q2(long N)
{
	int count1=0,count2=0;
	long i;
	for(i=0;i<N;i++){
		if(rv[i][0]==0 && rv[i][3]==1) count1++;
		if(rv[i][0]==0 && rv[i][3]==1 && rv[i][2]==0){
			count2++;
		}
	}
	return (double)count2/(double)count1;
}

double Q3(long N)
{
	int count1=0,count2=0;
	long i;
	for(i=0;i<N;i++){
		if(rv[i][0]==1) count1++;
		if(rv[i][0]==1 && rv[i][3]==0){
			count2++;
		}
	}
	return (double)count2/(double)count1;
}


int Denominator(long N)
{
	int i,j=0,count=0,check=0;
	for(i=0;i<4;i++){
		if(input[1][i]!=-1){
			check++;
			save[j]=i;
			j++;
		}
	}
	for(i=0;i<N;i++){
		switch (check){
			case(0):
				printf("error\n");
				break;
			case(1):
				if(rv[i][save[0]]==input[1][save[0]]) count++;
				break;
			case(2):
				if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]]) count++;
				break;
			case(3):
				if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save[2]]==input[1][save[2]]) count++;
				break;
			case(4):
				if(rv[i][0]==input[1][0] && rv[i][1]==input[1][1] && rv[i][2]==input[1][2] && rv[i][3]==input[1][3]) count++;
				break;
		}
	}
	return count;
}

int Numerator(long N)
{
	int i,j=0,k=0,count=0,check=0,check1=0;
	for(i=0;i<4;i++){
		if(input[1][i]!=-1){
			check++;
			save[j]=i;
			j++;
		}
		if(input[0][i]!=-1){
			check1++;
			save1[k]=i;
			k++;
		}
	}
	for(i=0;i<N;i++){
		switch (check){
			case(0):
				printf("error\n");
				break;
			case(1):
				if(check1==0){
					printf("error\n");
				}else if(check1==1){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save1[0]]==input[0][save1[0]]) count++;
				}else if(check1==2){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[1]]==input[0][save1[1]]) count++;
				}else if(check1==3){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[1]]==input[0][save1[1]] && rv[i][save1[2]]==input[0][save1[2]]) count++;
				}else if(check1==1){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[1]]==input[0][save1[1]] && rv[i][save1[2]]==input[0][save1[2]] && rv[i][save1[3]]==input[0][save1[3]]) count++;
				}
				break;
			case(2):
				if(check1==0){
					printf("error\n");
				}else if(check1==1){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save1[0]]==input[0][save1[0]]) count++;
				}else if(check1==2){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[1]]==input[0][save1[1]]) count++;
				}else if(check1==3){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[1]]==input[0][save1[1]] && rv[i][save1[2]]==input[0][save1[2]]) count++;
				}else if(check1==1){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[0]]==input[0][save1[1]] && rv[i][save1[2]]==input[0][save1[2]] && rv[i][save1[3]]==input[0][save1[3]]) count++;
				}
				break;
			case(3):
				if(check1==0){
					printf("error\n");
				}else if(check1==1){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save[2]]==input[1][save[2]] && rv[i][save1[0]]==input[0][save1[0]]) count++;
				}else if(check1==2){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save[2]]==input[1][save[2]]&& rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[1]]==input[0][save1[1]]) count++;
				}else if(check1==3){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save[2]]==input[1][save[2]]&& rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[1]]==input[0][save1[1]] && rv[i][save1[2]]==input[0][save1[2]]) count++;
				}else if(check1==1){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save[2]]==input[1][save[2]]&& rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[0]]==input[0][save1[1]] && rv[i][save1[2]]==input[0][save1[2]] && rv[i][save1[3]]==input[0][save1[3]]) count++;
				}
				break;
			case(4):
				if(check1==0){
					printf("error\n");
				}else if(check1==1){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save[2]]==input[1][save[2]] && rv[i][save[3]]==input[1][save[3]] && rv[i][save1[0]]==input[0][save1[0]]) count++;
				}else if(check1==2){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save[2]]==input[1][save[2]] && rv[i][save[3]]==input[1][save[3]] && rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[1]]==input[0][save1[1]]) count++;
				}else if(check1==3){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save[2]]==input[1][save[2]] && rv[i][save[3]]==input[1][save[3]] && rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[1]]==input[0][save1[1]] && rv[i][save1[2]]==input[0][save1[2]]) count++;
				}else if(check1==1){
					if(rv[i][save[0]]==input[1][save[0]] && rv[i][save[1]]==input[1][save[1]] && rv[i][save[2]]==input[1][save[2]] && rv[i][save[3]]==input[1][save[3]] && rv[i][save1[0]]==input[0][save1[0]] && rv[i][save1[0]]==input[0][save1[1]] && rv[i][save1[2]]==input[0][save1[2]] && rv[i][save1[3]]==input[0][save1[3]]) count++;
				}
				break;
		}
	}
	return count;
}


double culc(long N)
{
	int count1=Denominator(N);//分母
	int count2=Numerator(N);//分子
	return (double)count2/(double)count1;
}

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

void fileWrite()
{
	FILE *fp;
	long i=0;
	char input[100]={"a.txt"};
	fp=fopen(input,"w");
	for(i=0;i<MAX;i++){
		fprintf(fp,"%d  %d  %d  %d\n",(int)rv[i][0],(int)rv[i][1],(int)rv[i][2],(int)rv[i][3]);
	}
	fclose(fp);
}

void Input()
{
	int i,j;
	printf("P(A=x1,B=x2,C=x3,D=x4|A=y1,B=y2,C=y3,D=y4)\n");
	printf("x1~x4,y1~y4のところに0か1の値を入力してください\n");
	printf("それ以外の数字の場合は使わないとします\n");
	printf("例)条件付確率  P(A=1,D=0|B=0,D=0)を求めたいとき,\nx1=1,x2=2,x3=2,x4=0,y1=2,y2=0,y3=2,y4=0のように入力してください\n\n");
	printf("x1=");
	scanf("%d",&input[0][0]);
	printf("x2=");
	scanf("%d",&input[0][1]);
	printf("x3=");
	scanf("%d",&input[0][2]);
	printf("x4=");
	scanf("%d",&input[0][3]);
	printf("\n");
	printf("y1=");
	scanf("%d",&input[1][0]);
	printf("y2=");
	scanf("%d",&input[1][1]);
	printf("y3=");
	scanf("%d",&input[1][2]);
	printf("y4=");
	scanf("%d",&input[1][3]);
	printf("\n");
	for(i=0;i<2;i++){
		for(j=0;j<4;j++){
			if(input[i][j]!=0 && input[i][j]!=1){
				input[i][j]=-1;
			}
		}
	}
}

double Norm()
{
	long i=0,countA=0,countB=0,countC=0,countD=0;
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
	return i/Number;
}


int main()
{
	int i,k,j=0;
	double average=0;
	double ave;
	printf("最適値を計算してから、確立を求めたい場合は1を\n");
	printf("最大値でいいから、確立を求めたい場合は2を押してください\n");
	printf("推奨は2です\n");
	scanf("%d",&j);
	if(j==1){
		printf("動いてます\n");
		for(i=0;i<Number;i++){
			RandomGenerate();
			Change();
			average+=Norm();
			printf("%d\n",i);
		}
	}else if(j==2){
		average=MAX;
	}
	RandomGenerate();
	Change();
	printf("生成するサンプル数%d個\n",(long)average);
	printf("(1)P(D=1|B=1)=%lf\n",Q1((long)average));
	printf("(2)P(C=0|A=0,D=1)=%lf\n",Q2((long)average));
	printf("(3)P(D=0|A=1)=%lf\n",Q3((long)average));
	printf("\n");
	while(1){
		Input();
		printf("%4f",culc((long)average));
	}
	return 0;
}

