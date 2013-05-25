#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "11-12node.h"

struct score_node *make_list(FILE *fp);
struct score_node *search_node(char *name, struct score_node *head);
void free_list(struct score_node *head);

int main(void)
{
    	struct score_node *node;
	char	buf[50], name[20];
	FILE *fin;
	struct	score_node	*head;

	printf("2012�N�x��11�E12��A���S���Y���ƃf�[�^�\�����K(S)�ۑ�\n");

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

	head = make_list(fin);
	fclose(fin);

	/* �T���������� */
	printf("����?\n");
	if (gets(name) == NULL)
	{
		fprintf(stderr, "�T�������̎w�莞�ɃG���[���������܂���\n");
		exit(EXIT_FAILURE);
	}
	printf("\n");
	if ((node = search_node(name, head)) != NULL)
	{
		printf("�w���ԍ��F%d\t�����F%s\t���сF%d\n", node->no, node->name, node->score);
	}
	else
	{
		printf("%s�̃f�[�^�����݂��܂���\n", name);
	}
					
    
	free_list(head);
    	return 1;
}
