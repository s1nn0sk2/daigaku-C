#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int search(int key, struct student *array, int num_student);

int main(void)
{
    FILE *fin;
    int i, num_student, key, index;
	char buf[500], temp[50];
	struct student array[10];	//�w�����̃f�[�^�\��
	
	
	printf(" 2012�N�x��2��S�ۑ�1 \n");

	/* ���̓t�@�C�������w�肷�� */
	printf("���̓t�@�C�������w�肵�Ă�������\n");

	if (gets(buf) == NULL)
	{
		printf("���̓t�@�C�����̎w�莞�ɃG���[���������܂���\n");
		exit(EXIT_FAILURE);
	} 
        if((fin = fopen(buf, "r")) == NULL ) {
                fprintf(stderr,"���̓t�@�C���I�[�v���G���[\n");
                exit(EXIT_FAILURE);
	}

    	/* ���̓t�@�C������1�s�ǂݍ��� */
    for (i = 0; ; i++)
	{
		if (fgets(array[i].name, 50, fin) == NULL)
		{
			break;
		}
		 if (fgets(temp, 50, fin) == NULL)
		{
			break;
		}
		array[i].number = atoi(temp);
	}
	num_student = i;

	/* �w���ԍ��w�� */
	printf("�w���ԍ�����͂��Ă�������\n");
	if (gets(buf) == NULL)
	{
		printf("�w���ԍ��̎w�莞�ɃG���[���������܂���\n");
		exit(EXIT_FAILURE);
	} 
	/* �L�[�{�[�h���琮���ȊO����͂����ꍇ��key��0���ݒ肳��� */
	key = atoi(buf);

	
	/* �T���֐�search���R�[�� */
	index = search(key, array, num_student);

	/* �w������\�� */
	if (index >= 0)
	{
		printf("�w���ԍ�%d�̊w������%s�ł�\n", key, array[index].name);
	}
	else
	{
		printf("�w���ԍ�%d�̊w���͑��݂��܂���\n", key);
	}
    fclose(fin);

	return 0;
}
