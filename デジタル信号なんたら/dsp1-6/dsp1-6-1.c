#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	unsigned char id[4];			
	unsigned int size;		
	unsigned char form[4];			
} riff_chunk;

typedef struct{
	unsigned char id[4];			
	unsigned int size;		
	unsigned short format_id;	
	unsigned short channel;		
	unsigned long  fs;		
	unsigned long  byte_sec;	
	unsigned short byte_samp;	
	unsigned short bit;		
} fmt_chunk;

typedef struct{
	unsigned char id[4];
	unsigned int size;
	short pcm[1000000];
} data_chunk;

	riff_chunk riff={"RIFF",79760,"WAVE"};		
	fmt_chunk fmt={"fmt ",16,1,1,11025,22050,2,16};
	data_chunk data={"data",39862};

void getData(char input[100])
{
	FILE *read;
	int i=0;
	read = fopen(input,"r");
	fseek(read,0,SEEK_SET);
	while(fscanf(read,"%d",&data.pcm[i]) != EOF){
		i++;
	}
	fclose(read);
}

void createFile(char output[100])
{
	FILE *write;
	int i=0;
	
	write=fopen(output,"wb");
	fwrite(riff.id,sizeof(unsigned char),4,write);
	fwrite(&riff.size,sizeof(unsigned int),1,write);
	fwrite(&riff.form,sizeof(unsigned char),4,write);
	
	fwrite(fmt.id,sizeof(unsigned char),4,write);
	fwrite(&fmt.size,sizeof(unsigned int),1,write);
	fwrite(&fmt.format_id,sizeof(unsigned short),1,write);
	fwrite(&fmt.channel,sizeof(unsigned short),1,write);
	fwrite(&fmt.fs,sizeof(unsigned int),1,write);
	fwrite(&fmt.byte_sec,sizeof(unsigned int),1,write);
	fwrite(&fmt.byte_samp,sizeof(unsigned short),1,write);
	fwrite(&fmt.bit,sizeof(unsigned short),1,write);
	
	fwrite(data.id,sizeof(unsigned char),4,write);
	data.size*=2;
	fwrite(&data.size,sizeof(unsigned int),1,write);
	while(i <= data.size){
		fwrite(&data.pcm[i],sizeof(short),1,write);
		i++;
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
	createFile(output);
}
