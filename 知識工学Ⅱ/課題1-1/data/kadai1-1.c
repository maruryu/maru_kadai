#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char inputname[100];
char outputname[100];
double ave[47][196]={0};
int data;




int main(void)
{
	FILE *read,*write;
	int i,j,k;
	for(i=1;i<47;i++){
		sprintf(inputname,"c%02d.txt",i);
		read = fopen(inputname,"r");
		sprintf(outputname,"mean%02d.txt",i);
		write = fopen(outputname,"w");
		for(k=0;k<180;k++){
			for(j=0;j<196;j++){
				fscanf(read,"%d",&data);
				ave[i][j]+=data;
			}
		}
		for(j=0;j<196;j++){
			ave[i][j]=ave[i][j]/180;
			fprintf(write,"%lf\n",ave[i][j]);
		}
		fclose(read);
		fclose(write);
	}
	return 0;
} 