#include "kernel.h"
#include "kernel_id.h"
#include "MinSys3069.h"
#include "sample.h"

ID tskID_A, tskID_B;
ID cycID;

/* スタートアップルーチンから最初に呼び出される初期化関数 */
/* OS起動前にすること（SCIの初期化など）を行っておく      */
/* この関数からスタートアップルーチンに戻った後に，       */
/* スタートアップルーチンはHOSを呼び出す                  */
const static T_CTSK pk_ctskA={TA_HLNG, 1, checkButton, 5, 256, NULL};
const static T_CTSK pk_ctskB={TA_HLNG, 1, buttonHandler, 5, 256, NULL};
const static T_CCYC pk_ccyc={TA_HLNG, 1, CYC_wupCButton, 128};


void preStartHos()
{
	initSCI1();              /* SCIの初期化 */
	SCI1_printf("\npreStartHos: start!\n");  /* 開始メッセージ */
}


void OnHosStart(VP_INT exinf)
{
	ER_ID tskid;
	ER_ID cycid;
	
	tskid=acre_tsk(&pk_ctskA);
	if (E_OK<tskid) {
		tskID_A=tskid;
	} else {
		SCI1_printf("acre_tsk err %d",tskid);
	}

	tskid=acre_tsk(&pk_ctskB);
	if (E_OK<tskid) {
		tskID_B=tskid;
	} else {
		SCI1_printf("acre_tsk err %d",tskid);
	}
	
	cycid=acre_cyc(&pk_ccyc);
	if (E_OK<cycid) {
		cycID=cycid;
	} else {
		SCI1_printf("acre_cyc err %d",cycid);
	}
	act_tsk(tskID_A);
}

void CYC_wupCButton(VP_INT exinf)
{
	wup_tsk(tskID_A);
}

void checkButton(VP_INT exinf)
{
	static int oldbutton=0;
	int button;
	int stat;
	putStringSCI1("checkButton: starting!\n");
	sta_cyc(cycID);
	while(1) {
		slp_tsk();
		button=getPushSW();
		if ((stat=(oldbutton^button))) {
			if (oldbutton<button) { /*押された*/
				SCI1_printf("%d\n",stat);
				sta_tsk(tskID_B,stat);
			}
			oldbutton=button;
		}
	}
	ext_tsk();
}

#define	BTN0	0x01
#define	BTN1	0x02
#define	BTN2	0x04
#define	BTN3	0x08

void buttonHandler(VP_INT exinf)
{
	switch (exinf) {
	case BTN0:
		SCI1_printf("B0 PUSHED  \n");
		break;
	case BTN1:
		SCI1_printf("B1 PUSHED  \n");
		break;
	case BTN2:
		SCI1_printf("B2 PUSHED  \n");
		break;
	case BTN3:
		SCI1_printf("B3 PUSHED  \n");
		break;
	default:
		break;
	}
	ext_tsk();
}

