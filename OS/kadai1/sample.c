#include "kernel.h"
#include "kernel_id.h"
#include "MinSys3069.h"
#include "sample.h"


/* スタートアップルーチンから最初に呼び出される初期化関数 */
/* OS起動前にすること（SCIの初期化など）を行っておく      */
/* この関数からスタートアップルーチンに戻った後に，       */
/* スタートアップルーチンはHOSを呼び出す                  */
void preStartHos()
{
	initSCI1();              /* SCIの初期化 */
	SCI1_printf("\npreStartHos: start!\n");  /* 開始メッセージ */
}

/* HOS下で最初に起動するハンドラ*/
/* system.cfg中で静的に起動される */
void OnHosStart(VP_INT exinf)
{
	putStringSCI1("OnHosStart: starting!\n");
	act_tsk(TSKID_0);
	act_tsk(TSKID_1);
}

/* 1secごとにタイマの時間を表示するタスク */
/* system.cfg中で静的に生成され，OnHosStart()中で起動されている */
void printTime(VP_INT exinf)
{
	SYSTIM time;

	while (1) { /*永久ループ*/
		/* タイマ値取得 */
		get_tim(&time);
		
		/* タイマ値出力 */
		SCI1_printf("printTime:%8ld\n",(unsigned long int)time.ltime);
		
		/* 1000msec待つ(OSにCPU利用権を一時的に返し，時間になったら戻してもらう) */
		dly_tsk(1000);
	}
}

void primeNumber(VP_INT exinf){
	int j;
	int i=10001;
	int flag=0;
	while(1){
		flag=0;
		for(j=3;j<i;j+=2){
			if(i%j==0){
				flag=1;
			}
		}
		if(flag==0){
			SCI1_printf("primeNumber:%d\n",i);
		}
		i+=2;
	}
}
