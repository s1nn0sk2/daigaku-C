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

	printf("2012年度第13回アルゴリズムとデータ構造演習S課題\n");

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
	if (make_tbl(fin) == -1)
	{
		fprintf(stderr, "ハッシュテーブル作成時にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	}
	while (1)
   	{
       	printf("メニュー番号入力？\n");
		printf("1:探索\n");
		printf("2:終了\n");
		gets(buf);
		num_menu = atoi(buf);
		printf("\n");

        	if (!(num_menu >= 1 && num_menu <= 2))
        	{
          	  printf("1,2のいずれかの数字を入力してください！\n");
        	}
      	  	else if (num_menu == 2)
       		{
           		 break;
        	}
		else
		{
			printf("氏名?\n");
			gets(name);
			printf("\n");
		
			if ( (node = search_node(name)) != NULL)
			{
				printf("学生番号：%d\t氏名：%s\t成績：%d\n", node->no, node->name, node->score);
				printf("\n");
			}
			else
			{
				printf("%sのデータが存在しません\n", name);
			}
		}
    }
	/* ハッシュテーブル表示 */
	
	for (i = 0; i < 11; i++)
	{
		printf("Hash_tbl[%d]:\t", i);
		for (p = Hash_tbl[i]; p; p = p->next)
		{
			printf("%s, ", p->name);
		}
		printf("\n");
	}
	
    

    /* ハッシュテーブル削除 */
    free_tbl();
    
    return 1;
}


