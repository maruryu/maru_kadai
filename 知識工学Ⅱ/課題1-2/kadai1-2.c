#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char inputname[100];
char inputname2[100];
char outputname[100];
double ave[196];
int data[196][180];
double result[196][196]={0};

void fileRead()
{
	int i,j;
	FILE *read,*read2;
	read = fopen(inputname,"r");
	read2 = fopen(inputname2,"r");
	for(j=0;j<180;j++){
		for(i=0;i<196;i++){
			if(j==0) {
				fscanf(read2,"%lf",&ave[i]);
			}
			fscanf(read,"%d",&data[i][j]);
		}
	}
	fclose(read);
	fclose(read2);
}

void fileWrite()
{
	FILE *write;
	int i,j;
	write = fopen(outputname,"w");
	for(j=0;j<196;j++){
		for(i=0;i<195;i++){
			fprintf(write,"%lf	",result[i][j]);
		}
		fprintf(write,"%lf\n",result[195][j]);
	}
	fclose(write);
}

void covarianceCulc()
{
	int i,j,k;
	for(i=0;i<196;i++){
		for(j=0;j<196;j++){
			for(k=0;k<180;k++){
				result[i][j]+=(data[i][k]*data[j][k]);
			}
			result[i][j]=(((result[i][j])/180)-ave[i]*ave[j]);
		}
	}
}

int main(void)
{
	int i,j,k;
	for(i=1;i<47;i++){
		sprintf(inputname,"C:/Users/TeamET/Desktop/maru_kadai/’mŽ¯HŠw‡U/‰Û‘è1-2/data/c%02d.txt",i);
		sprintf(inputname2,"C:/Users/TeamET/Desktop/maru_kadai/’mŽ¯HŠw‡U/‰Û‘è1-2/wdata/mean%02d.txt",i);
		sprintf(outputname,"C:/Users/TeamET/Desktop/maru_kadai/’mŽ¯HŠw‡U/‰Û‘è1-2/covariancedata/sigma%02d.txt",i);
		fileRead();
		covarianceCulc();
		fileWrite();
	}
	return 0;
} 