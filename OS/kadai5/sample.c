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

/*                                              ↓優先順位     */
const static T_CTSK pk_ctskA={TA_HLNG, 1, primeNumber, 6, 256, NULL};
const static T_CTSK pk_ctskB={TA_HLNG, 1, printLine, 5, 256, NULL};
const static T_CTSK pk_ctskC={TA_HLNG, 1, printLine2, 5, 256, NULL};
ID tskID_A, tskID_B, tskID_C;
const static T_CFLG pk_cflg={(TA_TPRI | TA_WMUL),0};
ID flgID;

/* HOS下で最初に起動するハンドラ*/
/* system.cfg中で静的に起動される */
void OnHosStart(VP_INT exinf)
{
	ER_ID tskid; /*正ならID，負ならエラーコード*/
	ER_ID flgid; /*正ならID，負ならエラーコード*/
	putStringSCI1("OnHosStart: starting!\n");
	
	tskid=acre_tsk(&pk_ctskA);
	if (E_OK<tskid) {
		tskID_A=tskid;
		SCI1_printf("OnHosStart: A Pri,id= %d,%d\n",pk_ctskA.itskpri,tskid);
	} else {
		SCI1_printf("OnHosStart: acre_tsk A err %d\n",tskid);
	}
	
	tskid=acre_tsk(&pk_ctskB);
	if (E_OK<tskid) {
		tskID_B=tskid;
		SCI1_printf("OnHosStart: B Pri,id= %d,%d\n",pk_ctskB.itskpri,tskid);
	} else {
		SCI1_printf("OnHosStart: acre_tsk B err %d\n",tskid);
	}
	
	tskid=acre_tsk(&pk_ctskC);
	if (E_OK<tskid) {
		tskID_C=tskid;
		SCI1_printf("OnHosStart: C Pri,id= %d,%d\n",pk_ctskC.itskpri,tskid);
	} else {
		SCI1_printf("OnHosStart: acre_tsk C err %d\n",tskid);
	}
	
	flgid=acre_flg(&pk_cflg);
	if (E_OK<flgid) {
		flgID=flgid;
		SCI1_printf("OnHosStart: flgid=%d\n",flgID);
	} else {
		SCI1_printf("OnHosStart: acre_flg err %d\n",flgid);
	}

  /* タスクを起動（起動順序に注意） */

	act_tsk(tskID_B);
	act_tsk(tskID_C);
	act_tsk(tskID_A);
}

void primeNumber(VP_INT exinf)
{
	int i,j,flag,count;
	T_RFLG pk_rflg;
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
		if(flag==0){
			SCI1_printf("primeNumber:%d\n",i);
			count++;
			if(count%50==0){
				set_flg(flgID,2);
			}else if(count%5==0){
				set_flg(flgID,1);
			}
		}
		i+=2;
	}
	ext_tsk();
}

void printLine(VP_INT exinf)
{
	T_RFLG pk_rflg;
	FLGPTN flgptn;
	while(1){
		wai_flg(flgID,1,TWF_ANDW,&flgptn);
		putStringSCI1("--------\n");
		clr_flg(flgID,~1);
	}
	ext_tsk();
}

void printLine2(VP_INT exinf)
{
	T_RFLG pk_rflg;
	FLGPTN flgptn;
	while(1){
		wai_flg(flgID,2,TWF_ANDW,&flgptn);
		putStringSCI1("========\n");
		clr_flg(flgID,~2);
	}
	ext_tsk();
}

