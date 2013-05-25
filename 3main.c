#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3personal.h"

void inputfile(FILE *fp, struct personal_data *array, int num_student);
void outputfile(struct personal_data *array, int num_student);


int main(void)
{

	char	buf[500];
	struct	personal_data *array;
	int		num_student;
	FILE	*fin;


	printf("����24�N�x��3��A���S���Y���ƃf�[�^�\�����K(S)\n");
	/* ���̓t�@�C�������w�肷�� */
	printf("���̓t�@�C�������w�肵�Ă�������\n");

	if (gets(buf) == NULL)
	{
		fprintf(stderr, "���̓t�@�C�����̎w�莞�ɃG���[���������܂���\n");
		exit(EXIT_FAILURE);
	} 
    	if((fin = fopen(buf, "r")) == NULL ) {
        	fprintf(stderr,"���̓t�@�C���I�[�v���G���[\n");
        	exit(EXIT_FAILURE);
	}
	
	/* �w�������w�肷�� */
	
	while (1)
	{
		printf("�w�������w�肵�Ă�������\n");
		if (gets(buf) == NULL)
		{
			printf("���̓t�@�C�����̎w�莞�ɃG���[���������܂���\n");
			exit(EXIT_FAILURE);
		}
		num_student = atoi(buf);
		if (num_student == 0)
		{
			printf("�w�肳�ꂽ�w�������Ⴂ�܂��I1�ȏ�̐�������͂��Ă��������I\n");
		}
		else
		{
			break;
		}
	}
    
	if ( (array = calloc( num_student, sizeof( struct personal_data ) )) == NULL)
    	{
       		printf("Not allocate memory !\n");
	   	exit(1);
   	}
   
    	inputfile(fin, array, num_student);
	outputfile(array, num_student);

    

    
    	free(array);
	printf("����ɏI�����܂����B\n");
	printf("output.txt�t�@�C�����I�[�v�����Ĕz��array�̃f�[�^���m�F��������\n");
	return 0;
}


