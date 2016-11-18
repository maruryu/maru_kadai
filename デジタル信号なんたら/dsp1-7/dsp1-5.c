//***H27�N�x�EDSP1-5�E�ԍ�31***//
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


struct xn{
	double re;
	double im;
};

struct xn xn[100000]={0};
struct xn Xk[100000]={0};

int count=0;

void Hamming_window(int point)
{
	double j=0.54 ,k=1-j;
	int i;
	for(i=0;i<point;i++){
		xn[i].re = xn[i].re*(j-k*cos((2*M_PI*i)/point));
	}
}

void Hanning_window(int point)
{
	double j=0.5 ,k=1-j;
	int i;
	for(i=0;i<point;i++){
		xn[i].re = xn[i].re*(j-k*cos((2*M_PI*i)/point));
	}
}

void Blackman_window(int point)
{
	int i;
	for(i=0;i<point;i++){
		xn[i].re = 0.42-(0.5*cos((2*M_PI*i)/point))+(0.08*cos((4*M_PI*i)/point));
	}
}

double DbSpectrum(int i)
{
	double j=sqrt(pow(Xk[i].re,2)+pow(Xk[i].im,2));
	count+=4;
	return 20*log10(fabs(j));
	//return j;
}

double HzSpectrum(int i)
{
	if( fabs(Xk[i].im) >0.00001 && fabs(Xk[i].re) >0.00001){
		
		double j=atan2(Xk[i].im,Xk[i].re);
		count+=2;
		return j*180/M_PI;
		//return j;
	}else{
		return 0;
	}
}

void DFT_culc(int mode,int point)
{
	int i,j,a=1,b=1;
	for(i=0;i<point;i++){
		for(j=0;j<point;j++){
			Xk[j].re+=(xn[i].re*cos((2*M_PI*i*j)/point)+a*xn[i].im*sin((2*M_PI*i*j)/point))/b;
			Xk[j].im+=(xn[i].im*cos((2*M_PI*i*j)/point)-a*xn[i].re*sin((2*M_PI*i*j)/point))/b;
			count+=24;
		}
	}
}


void fileRead(char input[100],int mode)
{
	FILE *fp;
	int i=0;
	fp=fopen(input,"r");
	while(fscanf(fp,"%lf",&xn[i].re)!=EOF)
	{
		xn[i].im=0;
		i++;
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
			fprintf(fp,"%lf,",DbSpectrum(i));
			fprintf(fp,"%lf\n",HzSpectrum(i));
		}
	}else{
		for(i=0;i<point;i++){
			fprintf(fp,"%lf,%lf\n",Xk[i].re,Xk[i].im);
		}
	}
	fclose(fp);
}
void Divided_case()
{
	int i,mode,point,windowType=0,type=0;
	char input[100]={'\n'},output[100]={'\n'},hwoutput[100]={'\n'};
	printf("DFT -->1 or IDFT -->2\n");
	scanf("%d",&mode);
	printf("�_��N����͂��Ă��������D\n");
	scanf("%d",&point);
	printf("���̓t�@�C�������L�����Ă�������\n");
	scanf("%100s",input);
	printf("�o�̓t�@�C�������L�����Ă�������\n");
	scanf("%100s",output);

	printf("�U���X�y�N�g��[dB]�C�ʑ��X�y�N�g��[deg]���o�́�1\nDFT���ʂ����̂܂܏o�́�other\n");
	scanf("%d",&type);
	clock_t start, end;
	count=0;
	start = clock();

	fileRead(input,mode);
	DFT_culc(mode,point);
	fileWrite(output,point,mode,type);
	
	end = clock();
	printf( "��������:%d[ms]\n", end - start );
	printf( "�v�Z��:%d[��]\n", count );

}

int main()
{
	printf("H27�N�x�EDSP1-4�E�ԍ�31\n");
	printf("*****�g����**************************************\n");
	printf("*TEXT�f�[�^��DFT(IDFT)���܂�                    *\n");
	printf("*   �E���̓f�[�^�t�@�C��                        *\n");
	printf("*     (DFT�̎��͈��)                           *\n");
	printf("*     (IDFT�̎��͎����Ƌ����̓��:�X�y�[�X���) *\n");
	printf("*   �EDFT(IDFT)�o�̓t�@�C��                     *\n");
	printf("*     (DFT�̎��͎����Ƌ����̓��:�X�y�[�X���)  *\n");
	printf("*     (IDFT�̎��͈��)                          *\n");
	printf("*************************************************\n");
	Divided_case();
	return 0;
}
