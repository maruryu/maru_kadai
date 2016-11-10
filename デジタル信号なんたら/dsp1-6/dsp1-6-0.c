#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
	unsigned char id[5];			
	unsigned int size;		
	unsigned char form[5];			
} riff_chunk;

typedef struct{
	unsigned char id[5];			
	unsigned int size;		
	unsigned short format_id;	
	unsigned short channel;		
	unsigned long  fs;		
	unsigned long  byte_sec;	
	unsigned short byte_samp;	
	unsigned short bit;		
} fmt_chunk;

typedef struct{
	unsigned char id[5];
	unsigned int size;
	double time;
	short pcm[1000000];
} data_chunk;

	riff_chunk riff;		
	fmt_chunk fmt;
	data_chunk data;

void getData(char input[100]){
	FILE *read;
	int i;

	read = fopen(input,"rb");
	fseek(read,0,SEEK_SET);

	fread(riff.id, sizeof(unsigned char),4,read);
	fread(&riff.size, sizeof(unsigned int),1,read);
	fread(&riff.form, sizeof(unsigned char),4,read);

	fread(fmt.id, sizeof(unsigned char),4,read);
	fread(&fmt.size, sizeof(unsigned int),1,read);
	fread(&fmt.format_id, sizeof(unsigned short),1,read);
	fread(&fmt.channel, sizeof(unsigned short),1,read);
	fread(&fmt.fs, sizeof(unsigned int),1,read);
	fread(&fmt.byte_sec, sizeof(unsigned int),1,read);
	fread(&fmt.byte_samp, sizeof(unsigned short),1,read);
	fread(&fmt.bit, sizeof(unsigned short),1,read);

	fread(data.id, sizeof(unsigned char),4,read);
	fread(&data.size, sizeof(unsigned int),1,read);
	data.size/=2;
	data.time = (double)data.size/(double)fmt.fs;

	fread(&data.pcm,sizeof(short),data.size,read);

	fclose(read);
}

void printData(char output[100]){
	int i,j;
	FILE *write;
	
	write=fopen(output,"w");
	printf("%d\n",riff.size);
	printf("%d\n",fmt.channel);
	printf("%d\n",fmt.fs);
	printf("%d\n",fmt.bit);
	printf("%d\n",data.size);
	printf("%lf\n",data.time);
	j=(int)data.size;
	for(i=0;i<j;i++){
		fprintf(write,"%lf\n",data.pcm[i]);
	}
	fclose(write);
}
int main(){
	char input[100] = {'\n'};
	char output[100] = {'\n'};
	printf("入力するファイル名をうってください\n");
	scanf("%100s",input);
	printf("出力するファイル名をうってください\n");
	scanf("%100s",output);

	getData(input);
	printData(output);
}
