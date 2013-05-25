#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "6-7-8rpoland.h"

int	stackgen(void);
void	polish(struct pval_tbl *priority_tbl, char *equation, char *r_poland);
void	priority_set(struct pval_tbl *priority_tbl);
void	value_set(FILE *fp, struct pval_tbl *priority_tbl);
int	eval(struct pval_tbl * priority_tbl, char *r_poland);

int main(void)
{
	FILE *fin1, *fin2;
	char	buf[100], equation[100], r_poland[100], value[100];
	struct pval_tbl	priority_tbl[256];
	int	eval_result;



	/* �l�����Z���t�@�C�������w�肷�� */
	printf("�l�����Z���t�@�C�������w�肵�Ă�������\n");

	if (gets(buf) == NULL)
	{
		fprintf(stderr, "���̓t�@�C�����̎w�莞�ɃG���[���������܂���\n");
		exit(EXIT_FAILURE);
	}
	/* �l�����Z���t�@�C�����I�[�v�� */ 
    	if((fin1 = fopen(buf, "r")) == NULL ) {
        	fprintf(stderr,"���̓t�@�C���I�[�v���G���[\n");
        	exit(EXIT_FAILURE);
	}

	/* ���̓ǂݍ��� */
	if (fgets(equation, 100, fin1) == NULL)
	{
		fprintf(stderr,"�����ǂݍ��߂܂���\n");
        	exit(EXIT_FAILURE);
	}

	/* �ϐ��l�t�@�C�������w�肷�� */
	printf("�ϐ��l�t�@�C�������w�肵�Ă�������\n");

	if (gets(buf) == NULL)
	{
		fprintf(stderr, "���̓t�@�C�����̎w�莞�ɃG���[���������܂���\n");
		exit(EXIT_FAILURE);
	}
	/* �ϐ��l�t�@�C�����I�[�v�� */
	if((fin2 = fopen(buf, "r")) == NULL ) {
        	fprintf(stderr,"���̓t�@�C���I�[�v���G���[\n");
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

	/* �ϐ��l��D�揇�ʕ\�ɋL�� */
	value_set(fin2, priority_tbl);

	/* �ʏ�̐������t�|�[�����h���ɕϊ� */
	polish(priority_tbl, equation, r_poland);

	/* �t�|�[�����h���ɒl�������ĕ]�� */
	eval_result = eval(priority_tbl, r_poland);
	
	printf("�l�����Z���F%s\n", equation);
	rewind(fin2);
	while(fgets(value, 100, fin2) != NULL)
	{
		printf("%s", value);
	}
	printf("�l�����Z���̉𓚁F%d\n", eval_result);
	fclose(fin1);
	fclose(fin2);
	return 0;

}