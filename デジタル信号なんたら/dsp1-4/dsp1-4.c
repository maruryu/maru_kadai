//***H27年度・DSP1-4・番号31***//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double Cross_Correlation_Function(double x[],double y[],int m,int n)
{
	int i,j;
	double innerproduct=0,cross_correlation;
	for(i=0,j=m;j<n;i++,j++)
	{
		innerproduct+=x[i]*y[j];
	}
	cross_correlation=innerproduct/n;
	return cross_correlation;
}


double Autocorrelation_Coefficient_Function(double x[],int m,int n)
{
	int i,j;
	double innerproduct=0,autocorrelation_coefficient;
	for(i=0,j=m;j<n;i++,j++)
	{
		innerproduct+=x[i]*x[j];
	}
	autocorrelation_coefficient=innerproduct/n;
	return autocorrelation_coefficient;
}


int main()
{
	int i,j;
	double cross_correlation=0,autocorrelation_coefficient=0;
	FILE *fp;
	FILE *fq;
	char file[3][500]={"wdata1.txt","wdata2.txt","data3.txt"};
	double data[3][1000]={0};
	
	printf("H27年度・DSP1-4・番号31\n");
	printf("使い方:wdata1とwdata2のファイルに相互相関したいものを入れてください\n");
	printf("data3のファイルに自己相関したいものを入れてください\n");
	printf("相互相関した結果はresult.txtに出力されます\n");
	printf("自己相関した結果はresult2.txtに出力されます\n");
	
	for(i=0;i<2;i++)
	{
		fp=fopen(file[i],"r");
		j=0;
		while(fscanf(fp,"%lf",&data[i][j])==1)
		{
			j++;
		}
		fclose(fp);
	}
	fp=fopen("result.txt","w");
	
	printf("相互相関:");
	for(i=0;i<j;i++)
	{
		cross_correlation=Cross_Correlation_Function(data[0],data[1],i,j);
		fprintf(fp,"%.3f\n",cross_correlation);
		if(i%100==0)
		{
			printf("Rxy(%d)=%.3f\n",i,cross_correlation);
		}
	}
	
	
	fclose(fp);

	printf("\n");
	
	i=2;
	fq=fopen(file[2],"r");
	j=0;
	while(fscanf(fq,"%lf",&data[2][j])==1)
	{
		j++;
	}
	fclose(fq);
	
	fq=fopen("result2.txt","w");
	printf("自己相関:");

	for(i=0;i<j;i++)
	{
		autocorrelation_coefficient=Autocorrelation_Coefficient_Function(data[2],i,j);
		fprintf(fp,"%.3f\n",autocorrelation_coefficient);
		if(i%10==0)
		{
			printf("Rxy(%d)=%.3f\n",i,autocorrelation_coefficient);
		}
	}
	fclose(fq);
	
	return 0;
}