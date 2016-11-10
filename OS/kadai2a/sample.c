#include "kernel.h"
#include "kernel_id.h"
#include "MinSys3069.h"
#include "sample.h"

ID tskID1;
ID tskID2;
/* �X�^�[�g�A�b�v���[�`������ŏ��ɌĂяo����鏉�����֐� */
/* OS�N���O�ɂ��邱�ƁiSCI�̏������Ȃǁj���s���Ă���      */
/* ���̊֐�����X�^�[�g�A�b�v���[�`���ɖ߂�����ɁC       */
/* �X�^�[�g�A�b�v���[�`����HOS���Ăяo��                  */
void preStartHos()
{
	initSCI1();              /* SCI�̏����� */
	SCI1_printf("\npreStartHos: start!\n");  /* �J�n���b�Z�[�W */
}

/* HOS���ōŏ��ɋN������n���h��*/
/* system.cfg���ŐÓI�ɋN������� */
void OnHosStart(VP_INT exinf)
{
	const static T_CTSK pk_ctsk ={TA_HLNG, 1, printTime, 1, 128, NULL};
	const static T_CTSK pn_ctsk ={TA_HLNG, 1, primeNumber, 5, 128, NULL};
	
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

	tskid2=acre_tsk(&pn_ctsk);
	if (E_OK<tskid2) {
		tskID2=tskid2;
		act_tsk(tskID2);
	} else {
		SCI1_printf("acre_tsk err %d",tskid2);
	}

}

/* 1sec���ƂɃ^�C�}�̎��Ԃ�\������^�X�N */
/* system.cfg���ŐÓI�ɐ�������COnHosStart()���ŋN������Ă��� */
void printTime(VP_INT exinf)
{
	SYSTIM time;
	int flag=0;

	while (1) { /*�i�v���[�v*/
		/* �^�C�}�l�擾 */
		get_tim(&time);
		if(time.ltime>3000 && flag==0){
			chg_pri(tskID2,2);
			flag=1;
		}
		/* �^�C�}�l�o�� */
		SCI1_printf("printTime:%8ld\n",(unsigned long int)time.ltime);
		
		
		/* 1000msec�҂�(OS��CPU���p�����ꎞ�I�ɕԂ��C���ԂɂȂ�����߂��Ă��炤 */
		dly_tsk(1000);
	}
}

void primeNumber(VP_INT exinf){
	int i,j;
	int flag=0;
	SCI1_printf("primeNumber:2\n");
	for(i=3;i<=10000;i+=2){
		flag=0;
		for(j=3;j<i;j+=2){
			if(i%j==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			SCI1_printf("primeNumber:%8ld\n",(unsigned long int)i);
		}
	}
}
