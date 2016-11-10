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

ID tskID1;
ID tskID2;

/* HOS下で最初に起動するハンドラ*/
/* system.cfg中で静的に起動される */
void OnHosStart(VP_INT exinf)
{
	const static T_CTSK pk_ctsk ={TA_HLNG, 1, primeNumber, 6, 128, NULL};
	const static T_CTSK pk_ctsk2 ={TA_HLNG, 1, printLine, 1, 128, NULL};
	
	ER_ID tskid1;
	ER_ID tskid2;
	
	putStringSCI1("OnHosStart: starting!\n");
	tskid1=acre_tsk(&pk_ctsk);
	if (E_OK<tskid1) {
		tskID1=tskid1;
		act_tsk(tskID1);
	} else {
		SCI1_printf("acre_tsk err %d",tskid1);
	}

	tskid2=acre_tsk(&pk_ctsk2);
	if (E_OK<tskid2) {
		tskID2=tskid2;
		act_tsk(tskID2);
	} else {
		SCI1_printf("acre_tsk err %d",tskid2);
	}

}

void primeNumber(VP_INT exinf)
{
	int i,j,flag,count;
	i=10001;
	count=0;
	while(1){
		flag=0;
		for(j=3;j<i;j+=2){
			if(i%j==0){
				flag=1;
				break;
			}
		}
		if(count==10){
			wup_tsk(tskID2);
			count=0;
		}
		if(flag==0){
			SCI1_printf("primeNumber:%d\n",i);
			count++;
		}
		i+=2;
	}
	ext_tsk();
}

void printLine(VP_INT exinf)
{

	while(1){
		slp_tsk();
		putStringSCI1("--------\n");
	}
	ext_tsk();
}