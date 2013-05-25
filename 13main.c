#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "11-12node.h"


int hash_func(char *name);
struct score_node *search_node(char *name);
int	make_tbl( FILE *fp);
extern struct score_node *Hash_tbl[11];
void free_tbl(void);

int main(void)
{
    struct score_node *node, *p;
	FILE	*fin;
	char	name[20], buf[50];
	int	num_menu;
	int	i;

	printf("2012�N�x��13��A���S���Y���ƃf�[�^�\�����KS�ۑ�\n");

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
	if (make_tbl(fin) == -1)
	{
		fprintf(stderr, "�n�b�V���e�[�u���쐬���ɃG���[���������܂���\n");
		exit(EXIT_FAILURE);
	}
	while (1)
   	{
       	printf("���j���[�ԍ����́H\n");
		printf("1:�T��\n");
		printf("2:�I��\n");
		gets(buf);
		num_menu = atoi(buf);
		printf("\n");

        	if (!(num_menu >= 1 && num_menu <= 2))
        	{
          	  printf("1,2�̂����ꂩ�̐�������͂��Ă��������I\n");
        	}
      	  	else if (num_menu == 2)
       		{
           		 break;
        	}
		else
		{
			printf("����?\n");
			gets(name);
			printf("\n");
		
			if ( (node = search_node(name)) != NULL)
			{
				printf("�w���ԍ��F%d\t�����F%s\t���сF%d\n", node->no, node->name, node->score);
				printf("\n");
			}
			else
			{
				printf("%s�̃f�[�^�����݂��܂���\n", name);
			}
		}
    }
	/* �n�b�V���e�[�u���\�� */
	
	for (i = 0; i < 11; i++)
	{
		printf("Hash_tbl[%d]:\t", i);
		for (p = Hash_tbl[i]; p; p = p->next)
		{
			printf("%s, ", p->name);
		}
		printf("\n");
	}
	
    

    /* �n�b�V���e�[�u���폜 */
    free_tbl();
    
    return 1;
}


