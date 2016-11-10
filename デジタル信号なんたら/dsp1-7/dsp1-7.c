//***H28年度・DSP1-7・番号31***//
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct xn{
	double re;
	double im;
};

struct xn xn[500000]={0};
struct xn Xk[500000]={0};
struct xn in1;
struct xn in2;

struct xn complexAdd(struct xn in1,struct xn in2)
{
	
}

double DbSpectrum(int i)
{
	double j=sqrt(pow(Xk[i].re,2)+pow(Xk[i].im,2));
	return 20*log10(fabs(j));
	//return j;
}

double HzSpectrum(int i)
{
	if( fabs(Xk[i].im) >0.00001 && fabs(Xk[i].re) >0.00001){
		
		double j=atan2(Xk[i].im,Xk[i].re);
		//return j*180/M_PI;
		return j;
	}else{
		return 0;
	}
}

void DFT_culc(int mode,int point)
{
	int i,j,a,b;
	if(mode==1){
		a=1;
		b=1;
	}else if(mode==2){
		a=-1;
		b=point;
	}
	for(i=0;i<point;i++){
		for(j=0;j<point;j++){
			Xk[j].re+=(xn[i].re*cos((2*M_PI*i*j)/point)+a*xn[i].im*sin((2*M_PI*i*j)/point))/b;
			Xk[j].im+=(xn[i].im*cos((2*M_PI*i*j)/point)-a*xn[i].re*sin((2*M_PI*i*j)/point))/b;
		}
	}
}


void fileRead(char input[100],int mode)
{
	FILE *fp;
	int i=0;
	fp=fopen(input,"r");
	if(mode==1){
		while(fscanf(fp,"%lf",&xn[i].re)!=EOF)
		{
			xn[i].im=0;
			i++;
		}
	}else if(mode==2){
		while(fscanf(fp,"%lf  %lf",&xn[i].re,&xn[i].im)!=EOF)
		{
			i++;
		}
	}
	fclose(fp);
}

void fileWrite(char output[100],int point,int mode,int type)
{
	FILE *fp;
	int i=0;
	fp=fopen(output,"w");
	if(type==1){
		for(i=0;i<point;i++){
			fprintf(fp,"%lf  ",DbSpectrum(i));
			fprintf(fp,"%lf\n",HzSpectrum(i));
		}
	}else if(mode==1){
		for(i=0;i<point;i++){
			fprintf(fp,"%lf  %lf\n",Xk[i].re,Xk[i].im);
		}
	}else if(mode==2){
		for(i=0;i<point;i++){
			fprintf(fp,"%lf\n",Xk[i].re);
		}
	}else{
		for(i=0;i<point;i++){
			fprintf(fp,"%lf\n",xn[i].re);
		}
	}
	fclose(fp);
}
void Divided_case()
{
	int i,mode,point,type=0;
	char input[100]={'\n'},output[100]={'\n'},hwoutput[100]={'\n'};
	printf("DFT -->1 or IDFT -->2\n");
	scanf("%d",&mode);
	if(mode==1){
		printf("振幅スペクトル[dB]，位相スペクトル[deg]を出力→1\nDFT結果をそのまま出力→other\n");
		scanf("%d",&type);
		printf("点数Nを入力してください．\n");
		scanf("%d",&point);
		printf("入力ファイル名を記入してください\n");
		scanf("%100s",input);
		printf("出力ファイル名を記入してください\n");
		scanf("%100s",output);
		
		fileRead(input,mode);
		DFT_culc(mode,point);		
	}else if(mode==2){
	
		printf("点数Nを入力してください．\n");
		scanf("%d",&point);
		printf("入力ファイル名を記入してください\n");
		scanf("%100s",input);
		printf("出力ファイル名を記入してください\n");
		scanf("%100s",output);
		
		fileRead(input,mode);
		DFT_culc(mode,point);
	}
	fileWrite(output,point,mode,type);
}

void main()
{
	Divided_case();
}
