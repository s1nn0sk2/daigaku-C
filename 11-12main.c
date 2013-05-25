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

	printf("2012年度第11・12回アルゴリズムとデータ構造演習(S)課題\n");

	/* 入力ファイル名を指定する */
	printf("入力ファイル名を指定してください\n");

	if (gets(buf) == NULL)
	{
		fprintf(stderr, "入力ファイル名の指定時にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	} 
    	if((fin = fopen(buf, "r")) == NULL ) {
        	fprintf(stderr,"入力ファイルオープンエラー\n");
        	exit(EXIT_FAILURE);
	}

	head = make_list(fin);
	fclose(fin);

	/* 探索氏名入力 */
	printf("氏名?\n");
	if (gets(name) == NULL)
	{
		fprintf(stderr, "探索氏名の指定時にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	}
	printf("\n");
	if ((node = search_node(name, head)) != NULL)
	{
		printf("学生番号：%d\t氏名：%s\t成績：%d\n", node->no, node->name, node->score);
	}
	else
	{
		printf("%sのデータが存在しません\n", name);
	}
					
    
	free_list(head);
    	return 1;
}
