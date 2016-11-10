//＊＊＊H27年度・DSP1-3・番号31＊＊＊

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double InnerProduct(double x[], double f[], int lineNumber)
{
	int i;
	double InnerProduct=0;
	for(i=0;i<lineNumber;i++)
	{
		InnerProduct+=x[i]*f[i];
	}
	return InnerProduct;
}

double Norm(double x[],double f[],int lineNumber)
{
	int i;
	double xn=0;
	double fn=0;
	double norm=0;
	for(i=0;i<lineNumber;i++)
	{
		xn+=x[i]*x[i];
		fn+=f[i]*f[i];
	}
	norm=sqrt(xn)*sqrt(fn);
	return norm;
}

double average(double x[],int lineNumber)
{
	double ave=0,sum=0;
	int i;
	for(i=0;i<lineNumber;i++)
	{
		sum+=x[i];
	}
	ave=sum/lineNumber;
	return ave;
}


double correlation_coefficient(double x[],double f[],int lineNumber,int conditions)
{
	int i;
	double ave[2];
	double xp[1000];
	double fp[1000];
	double norm=0;
	double ip=0;
	if(conditions==0)
	{
		ave[0]=average(x,lineNumber);
		ave[1]=average(f,lineNumber);
		
		for(i=0;i<lineNumber;i++)
		{
			xp[i]=x[i]-ave[0];
			fp[i]=f[i]-ave[1];
		}
		ip=InnerProduct(xp,fp,lineNumber);
		norm=Norm(xp,fp,lineNumber);
	}else
	{
		ip=InnerProduct(x,f,lineNumber);
		norm=Norm(x,f,lineNumber);
	}
	return ip/norm;
}
int main()
{
	int i,j=0;
	FILE *fp;
	char file[4][32]={"rdata1.txt","rdata2.txt","rdata3.txt","rdata4.txt"};
	double data[4][100]={0};
	for(i=0;i<4;i++)
	{
		fp=fopen(file[i],"r");
		j=0;
		while(fscanf(fp,"%lf",&data[i][j])==1)
		{
			j++;
		}
		fclose(fp);
	}
	printf("H27年度・DSP1-3・番号31\n");
	printf("使い方:rdata1～rdata4までのファイルに比べたいものを入れてください\n");

	
	printf("相関係数結果:\n");
	printf("H16男性・女性=%.3f\n",correlation_coefficient(data[0],data[1],j,0));
	printf("H16男性・総人口=%.3f\n",correlation_coefficient(data[0],data[2],j,0));
	printf("H16男性・S24=%.3f\n",correlation_coefficient(data[0],data[3],j,0));
	printf("\n");
	
	printf("直流成分未除去の場合：\n");
	printf("H16男性・女性=%.3f\n",correlation_coefficient(data[0],data[1],j,1));
	printf("H16男性・総人口=%.3f\n",correlation_coefficient(data[0],data[2],j,1));
	printf("H16男性・S24=%.3f\n",correlation_coefficient(data[0],data[3],j,1));
	return 0;
}

