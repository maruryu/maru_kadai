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

#define	BTN0	0x01
#define	BTN1	0x02
#define	BTN2	0x04
#define	BTN3	0x08
#define	BTN1P	0x1f
#define	BTN1R	0x10
#define	BTN2P	0x2f
#define	BTN2R	0x20
#define	BTN3P	0x3f
#define	BTN3R	0x30
#define	BTN4P	0x4f
#define	BTN4R	0x40

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
				switch (stat){
				case BTN0:
					sta_tsk(tskID_B,BTN1P);
					break;
				case BTN1:
					sta_tsk(tskID_B,BTN2P);
					break;
				case BTN2:
					sta_tsk(tskID_B,BTN3P);
					break;
				case BTN3:
					sta_tsk(tskID_B,BTN4P);
					break;
				default:
					break;
				}
			}
			oldbutton=button;
		}
	}
	ext_tsk();
}


void buttonHandler(VP_INT exinf)
{
	switch (exinf) {
	case BTN1P:
		turnOnLed(0);
		break;
	case BTN2P:
		turnOnLed(1);
		break;
	case BTN3P:
		turnOffLed(0);
		break;
	case BTN4P:
		turnOffLed(1);
		break;
	default:
		break;
	}
	ext_tsk();
}

