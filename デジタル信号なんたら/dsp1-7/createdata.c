#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	FILE *fp;
	int i=0;
	fp=fopen("data.txt","w");
	for(i=0;i<16384;i++){
		fprintf(fp,"%d\n",rand()%(10+10+1)-10);
	}
	fclose(fp);
}