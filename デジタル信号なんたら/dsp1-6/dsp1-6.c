#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	unsigned char id[5];
	unsigned long size;
	unsigned char form[5];
} riff_chunk;

typedef struct{
	unsigned char id[5];
	unsigned long size;
	unsigned short format_id;
	unsigned short channel;
	unsigned long  fs;
	unsigned long  byte_sec;
	unsigned short byte_samp;
	unsigned short bit;
} fmt_chunk;

typedef struct{
	unsigned char id[5];
	unsigned long size;
	double time;
	short pcm[1000000];
} data_chunk;

	riff_chunk riff={"RIFF",79760,"WAVE"};		
	fmt_chunk fmt={"fmt ",16,1,1,11025,22050,2,16};
	data_chunk data={"data"};
	
	
void getBdata(char input[100]){
	FILE *read;
	int i;

	read = fopen(input,"rb");
	fseek(read,0,SEEK_SET);

	fread(riff.id, sizeof(unsigned char),4,read);
	fread(&riff.size, sizeof(unsigned long),1,read);
	fread(&riff.form, sizeof(unsigned char),4,read);

	fread(fmt.id, sizeof(unsigned char),4,read);
	fread(&fmt.size, sizeof(unsigned long),1,read);
	fread(&fmt.format_id, sizeof(unsigned short),1,read);
	fread(&fmt.channel, sizeof(unsigned short),1,read);
	fread(&fmt.fs, sizeof(unsigned long),1,read);
	fread(&fmt.byte_sec, sizeof(unsigned long),1,read);
	fread(&fmt.byte_samp, sizeof(unsigned short),1,read);
	fread(&fmt.bit, sizeof(unsigned short),1,read);

	fread(data.id, sizeof(unsigned char),4,read);
	fread(&data.size, sizeof(unsigned long),1,read);
	data.size/=2;
	data.time = (double)data.size/(double)fmt.fs;

	fread(&data.pcm,sizeof(short),data.size,read);

	fclose(read);
}

void printTdata(char output[100]){
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
		fprintf(write,"%d\n",data.pcm[i]);
	}
	fclose(write);
}

void getTdata(char input[100])
{
	FILE *read;
	int i=0;
	read = fopen(input,"r");
	fseek(read,0,SEEK_SET);
	while(fscanf(read,"%d",&data.pcm[i]) != EOF){
		i++;
	}
	data.size=i;
	fclose(read);
}
void createBfile(char output[100])
{
	FILE *write;
	int i=0;
	
	write=fopen(output,"wb");
	fwrite(riff.id,sizeof(unsigned char),4,write);
	fwrite(&riff.size,sizeof(unsigned long),1,write);
	fwrite(&riff.form,sizeof(unsigned char),4,write);
	
	fwrite(fmt.id,sizeof(unsigned char),4,write);
	fwrite(&fmt.size,sizeof(unsigned long),1,write);
	fwrite(&fmt.format_id,sizeof(unsigned short),1,write);
	fwrite(&fmt.channel,sizeof(unsigned short),1,write);
	fwrite(&fmt.fs,sizeof(unsigned long),1,write);
	fwrite(&fmt.byte_sec,sizeof(unsigned long),1,write);
	fwrite(&fmt.byte_samp,sizeof(unsigned short),1,write);
	fwrite(&fmt.bit,sizeof(unsigned short),1,write);
	
	fwrite(data.id,sizeof(unsigned char),4,write);
	data.size*=2;
	fwrite(&data.size,sizeof(unsigned long),1,write);
	while(i <= (int)data.size){
		fwrite(&data.pcm[i],sizeof(short),1,write);
		i++;
	}
	fclose(write);
}

int main(){
	printf("H28年度・DSP1-6・番号31\n");
	printf("*****使い方**************************************\n");
	printf("*TEXT-->WAVEまたはWAVE-->TEXT変換を行います　   *\n");
	printf("*   ・入力・出力データファイル                  *\n");
	printf("*     拡張子を含めて入力してください 　　　　　 *\n");
	printf("*************************************************\n");
	char input[100] = {'\n'};
	char output[100] = {'\n'};
	int mode;
	
	printf("WAVE -->TEXT変換は0を，TEXT-->WAVE変換は1を入力してください\n");
	scanf("%d",&mode);
	printf("入力するファイル名をうってください\n");
	scanf("%100s",input);
	printf("出力するファイル名をうってください\n");
	scanf("%100s",output);
	if(mode==0){
		getBdata(input);
		printTdata(output);
	}else{
		getTdata(input);
		createBfile(output);
	}

}