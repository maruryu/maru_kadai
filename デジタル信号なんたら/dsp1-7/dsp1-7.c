//***H28�N�x�EDSP1-7�E�ԍ�31***//
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

typedef struct{
	double re;
	double im;
}comp;

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

void twid(comp *wnk,int N)
{
	double e=(2*M_PI/N);
	int i;
	for(i=0;i<N/2;i++){
		wnk[i].re = cos(e*i);
		wnk[i].im = sin(e*i);
	}
}

void Divided_case()
{
	int i,mode,point,type=0;
	char input[100]={'\n'},output[100]={'\n'},hwoutput[100]={'\n'};
	printf("DFT -->1 or IDFT -->2\n");
	scanf("%d",&mode);
	if(mode==1){
		printf("�U���X�y�N�g��[dB]�C�ʑ��X�y�N�g��[deg]���o�́�1\nDFT���ʂ����̂܂܏o�́�other\n");
		scanf("%d",&type);
		printf("�_��N����͂��Ă��������D\n");
		scanf("%d",&point);
		printf("���̓t�@�C�������L�����Ă�������\n");
		scanf("%100s",input);
		printf("�o�̓t�@�C�������L�����Ă�������\n");
		scanf("%100s",output);
		
		fileRead(input,mode);
		DFT_culc(mode,point);		
	}else if(mode==2){
	
		printf("�_��N����͂��Ă��������D\n");
		scanf("%d",&point);
		printf("���̓t�@�C�������L�����Ă�������\n");
		scanf("%100s",input);
		printf("�o�̓t�@�C�������L�����Ă�������\n");
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
