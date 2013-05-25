#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "6-7-8rpoland.h"

int	stackgen(void);
void	polish(struct pval_tbl *priority_tbl, char *equation, char *r_poland);
void	priority_set(struct pval_tbl *priority_tbl);


int main(void)
{
	FILE *fin;
	char	buf[100], equation[100], r_poland[100];
	struct pval_tbl	priority_tbl[256];


	printf("2012�N�x�@��6�E7�E8��A���S���Y���ƃf�[�^�\�����K(S)�ۑ�\n");

	/* ���̓t�@�C�������w�肷�� */
	printf("���̓t�@�C�������w�肵�Ă�������\n");

	if (gets(buf) == NULL)
	{
		fprintf(stderr, "���̓t�@�C�����̎w�莞�ɃG���[���������܂���\n");
		exit(EXIT_FAILURE);
	}
	/* ���̓t�@�C�����I�[�v�� */ 
    	if((fin = fopen(buf, "r")) == NULL ) {
        	fprintf(stderr,"���̓t�@�C���I�[�v���G���[\n");
        	exit(EXIT_FAILURE);
	}

	/* ���̓ǂݍ��� */
	if (fgets(equation, 100, fin) == NULL)
	{
		fprintf(stderr,"�����ǂݍ��߂܂���\n");
        	exit(EXIT_FAILURE);
	}


	/* �X�^�b�N���� */
	if (stackgen() == -1)
	{
		fprintf(stderr, "�X�^�b�N�̐����Ɏ��s���܂���\n");
		exit(EXIT_FAILURE);
	}

	/* �D�揇�ʕ\�쐬 */
	priority_set(priority_tbl);

	/* �ʏ�̐������t�|�[�����h���ɕϊ� */
	polish(priority_tbl, equation, r_poland);

	/* �t�|�[�����h����W���o�͂ɏo�� */
	printf("�ʏ�̎��F%s\n", equation);
	printf("�t�|�[�����h���F%s\n", r_poland);
	fclose(fin);
	return 0;

}