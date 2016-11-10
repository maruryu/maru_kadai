#include "kernel.h"
#include "kernel_id.h"
#include "MinSys3069.h"
#include "sample.h"


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
	putStringSCI1("OnHosStart: starting!\n");
	act_tsk(TSKID_0);
}

/* 1sec���ƂɃ^�C�}�̎��Ԃ�\������^�X�N */
/* system.cfg���ŐÓI�ɐ�������COnHosStart()���ŋN������Ă��� */
void printTime(VP_INT exinf)
{
	SYSTIM time;

	while (1) { /*�i�v���[�v*/
		/* �^�C�}�l�擾 */
		get_tim(&time);
		
		/* �^�C�}�l�o�� */
		SCI1_printf("printTime:%8ld\n",(unsigned long int)time.ltime);
		
		/* 1000msec�҂�(OS��CPU���p�����ꎞ�I�ɕԂ��C���ԂɂȂ�����߂��Ă��炤) */
		dly_tsk(1000);
	}
}

void primeNumber(VP_INT exinf){
	int i,j,flag=0;
	for(i=2;i<=10000;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				flag = 1;
				break;
			}
		}
		if(flag==0){
			SCI1_printf("primeNumber:%8d\n",i);
			dly_tsk(1000);
		}
	}
}
