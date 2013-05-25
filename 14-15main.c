#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "14-15personal.h"


int	bnry_search(struct personal_data *array, int  num, int key);
void make_array(FILE *fp, struct personal_data *array);
void	sort_score(struct personal_data *array, int num);
void	sort_id(struct personal_data *array, int num);

int main(void)
{
    struct personal_data *array;
	FILE	*fin;
	char	name[20], buf[50], temp[50], id[20];
	int	num_menu;
	int  i, j, index, key;

	printf("2012�N��14�E15��A���S���Y���ƃf�[�^�\�����K(S)�ۑ�\n");

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

	/* �w�����擾 */
	for (i = 0; ; i++)
	{
		if (fgets(temp, 50, fin) == NULL)
		{
			break;
		}
	}
	
	/* �w�����̃f�[�^�\���̗̈�𓮓I�Ɋm�� */
	if ( (array = (struct personal_data *)calloc(i, sizeof(struct personal_data))) == NULL )
	{
		printf("�w�����̃f�[�^�\���̗̈���m�ۂł��܂���ł���\n");
		exit(EXIT_FAILURE);
	}

	/* �t�@�C���̐擪�Ɉړ� */
	rewind(fin);


	make_array(fin, array);
	

	while (1)
   	{
       	printf("���j���[�ԍ����́H\n");
		printf("1:�T��\n");
		printf("2:�x�X�g10�\��\n");
		printf("3:�I��\n");
		gets(buf);
		num_menu = atoi(buf);
		printf("\n");

        	if (!(num_menu >= 1 && num_menu <= 3))
        	{
          	  printf("1,2,3�̂����ꂩ�̐�������͂��Ă��������I\n");
        	}
      	  	else if (num_menu == 3)
       		{
           		 break;
        	}
		else if (num_menu == 1)
		{
			printf("�w���ԍ�?\n");
			gets(id);
			printf("\n");
			key = atoi(id);
			sort_id(array, i);
		
			if ( (index = bnry_search(array, i, key)) != -1)
			{
				printf("�w���ԍ��F%d\t�����F%s\t���сF%d\n", array[index].id, array[index].name, array[index].score);
				printf("\n");
			}
			else
			{
				printf("�w���ԍ�%d�̃f�[�^�����݂��܂���\n", key);
			}
		}
		else	/* �x�X�g10�\�� */
		{
			sort_score(array, i);
			for (j = 0; j < 10; j++)
			{
				printf("���ʁF%d��\t�w���ԍ��F%d\t�����F%s\t���сF%d\n", j+1, array[j].id, array[j].name, array[j].score);
			}
		}
    }
    

    /* �z��폜 */
    free(array);
    
    return 1;
}


