#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct{
	double re;
	double im;
}comp;

int N;
int bitsize;
int mode=1;
int count=0;

comp answer[1000000];

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
	count+=4;
	return result;
}

comp compDiv(comp in1,comp in2)
{
	comp result;
	double molecule = pow(in2.re,2) + pow(in2.im,2);
	count+=2;
	result.re = ((in1.re*in2.re) + (in1.im*in2.im))/molecule;
	result.im = ((in1.im*in2.re) - (in1.re*in2.im))/molecule;
	count+=6;
	return result;
}

comp comj(comp in)
{
	
	in.im = -in.im;
	
	return in;
}

void bitRev(int *bit)
{
	int i,j,bn=1;
	bit[0]=0;

	for(i=0;i<bitsize;i++){
		for(j=0;j<bn;j++){
			bit[j+bn]=bit[j]+N/(bn*2);
			count+=2;
		}
		bn*=2;
		count++;
	}
}

void contentsChange(int *bit)
{
	int i;
	comp xcpy[N];
	for(i=0;i<N;i++){
		xcpy[i].re=answer[i].re;
	}
	for(i=0;i<N;i++){
		answer[bit[i]].re=xcpy[i].re;
	}
}


void twid(comp *rotor)
{
	double e=(2*M_PI/N);
	count+=2;
	int i,j;
	if(mode==1){
		j=-1;
	}else if(mode==2){
		j=1;
	}
	for(i=0;i<N/2;i++){
		rotor[i].re = cos(e*i);
		rotor[i].im = j*sin(e*i);
		count+=3;
	}
	count++;
}

void batCulc()
{
	int rinc=1,rdec=N/2;
	count++;
	int i,j,k,x,y,rot;
	comp rotor[N];
	twid(rotor);
	comp coefficient;
	for(i=0;i<bitsize;i++){
		for(j=0;j<rinc;j++){
			for(k=0;k<rdec;k++){
				x=rinc*2*k+j;
				y=x+rinc;
				rot=j*rdec;
				
				coefficient=compMulti(answer[y],rotor[rot]);
				answer[y]=compDec(answer[x],coefficient);
				answer[x]=compAdd(answer[x],coefficient);
				count+=3;
			}
		}
		rinc*=2;
		rdec/=2;
		count+=2;
	}
}

double DbSpectrum(int i)
{
	double j=sqrt(pow(answer[i].re,2)+pow(answer[i].im,2));
	count+=4;
	return 20*log10(fabs(j));
	//return j;
}

double HzSpectrum(int i)
{
	if( fabs(answer[i].im) >0.00001 && fabs(answer[i].re) >0.00001){
		
		double j=atan2(answer[i].im,answer[i].re);
		return j*180/M_PI;
		count+=2;
		//return j;
	}else{
		return 0;
	}
}


void fileRead(char input[100])
{
	FILE *fp;
	int i=0;
	fp=fopen(input,"r");
	while(fscanf(fp,"%lf",&answer[i].re)!=EOF)
	{
		answer[i].im=0;
		i++;
	}
	/*else if(mode==2){
		while(fscanf(fp,"%lf  %lf",&xn[i].re,&xn[i].im)!=EOF)
		{
			i++;
		}
	}*/
	fclose(fp);
}

void fileWrite(char output[100],int type)
{
	FILE *fp;
	int i=0;
	fp=fopen(output,"w");
	if(type==1){
		for(i=0;i<N;i++){
			fprintf(fp,"%lf,",DbSpectrum(i));
			fprintf(fp,"%lf\n",HzSpectrum(i));
		}
	}else{
		for(i=0;i<N;i++){
			fprintf(fp,"%lf,%lf\n",answer[i].re,answer[i].im);
		}
	}
	fclose(fp);
}


void Divided_case()
{
	int i,type=0;
	
	char input[100]={'\n'},output[100]={'\n'};
	
	printf("点数Nを入力してください．\n");
	scanf("%d",&N);
	printf("入力ファイル名を記入してください\n");
	scanf("%100s",input);
	printf("出力ファイル名を記入してください\n");
	scanf("%100s",output);
	printf("振幅スペクトル[dB]，位相スペクトル[deg]を出力→1\nFFT結果をそのまま出力→other\n");
	scanf("%d",&type);
	clock_t start, end;
	count=0;
	start = clock();
	int bit_r[N];
	bitsize=log2(N);

	fileRead(input);
	bitRev(bit_r);
	contentsChange(bit_r);
	batCulc();
	fileWrite(output,type);
	end = clock();
	printf( "処理時間:%d[ms]\n", end - start );
	printf( "計算回数:%d[回]\n", count );

}


int main()
{
	Divided_case();
	return 0;
}