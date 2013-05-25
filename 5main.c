#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3personal.h"

void inputfile(FILE *fp, struct personal_data *array, int num_student);
int	searchstring(struct personal_data *array, int num_student, char *string);


int main(void)
{

	char	buf[500];
	struct	personal_data *array;
	int		num_student, index;
	FILE	*fin;

	printf("2012�N�x��5��A���S���Y���ƃf�[�^�\�����K(S)\n");

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

	/* �w�������w�肷�� */
    	printf("�w�������w�肵�Ă�������\n");
	if (gets(buf) == NULL)
	{
		printf("���̓t�@�C�����̎w�莞�ɃG���[���������܂���\n");
		exit(EXIT_FAILURE);
	}
	
	/* �w�������L�[�Ƃ��Ĕz���T�� */
	/**** �v���O���~���O���Ă������� ****/
	index=searchstring(array,num_student,buf);
	if(index==-1){
		printf("���̊w���͑��݂��܂���");
	}else{
	printf("%d %s %d",array[index].id,array[index].name,array[index].score);
	}
    

    
    	free(array);
	printf("����ɏI�����܂����B\n");
	
	return 0;
}


