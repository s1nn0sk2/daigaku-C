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

	printf("2012年第14・15回アルゴリズムとデータ構造演習(S)課題\n");

	/* 入力ファイル名を指定する */
	printf("入力ファイル名を指定してください\n");

	if (gets(buf) == NULL)
	{
		printf("入力ファイル名の指定時にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	} 
        if((fin = fopen(buf, "r")) == NULL ) {
                fprintf(stderr,"入力ファイルオープンエラー\n");
                exit(EXIT_FAILURE);
	}

	/* 学生数取得 */
	for (i = 0; ; i++)
	{
		if (fgets(temp, 50, fin) == NULL)
		{
			break;
		}
	}
	
	/* 学生情報のデータ構造の領域を動的に確保 */
	if ( (array = (struct personal_data *)calloc(i, sizeof(struct personal_data))) == NULL )
	{
		printf("学生情報のデータ構造の領域を確保できませんでした\n");
		exit(EXIT_FAILURE);
	}

	/* ファイルの先頭に移動 */
	rewind(fin);


	make_array(fin, array);
	

	while (1)
   	{
       	printf("メニュー番号入力？\n");
		printf("1:探索\n");
		printf("2:ベスト10表示\n");
		printf("3:終了\n");
		gets(buf);
		num_menu = atoi(buf);
		printf("\n");

        	if (!(num_menu >= 1 && num_menu <= 3))
        	{
          	  printf("1,2,3のいずれかの数字を入力してください！\n");
        	}
      	  	else if (num_menu == 3)
       		{
           		 break;
        	}
		else if (num_menu == 1)
		{
			printf("学生番号?\n");
			gets(id);
			printf("\n");
			key = atoi(id);
			sort_id(array, i);
		
			if ( (index = bnry_search(array, i, key)) != -1)
			{
				printf("学生番号：%d\t氏名：%s\t成績：%d\n", array[index].id, array[index].name, array[index].score);
				printf("\n");
			}
			else
			{
				printf("学生番号%dのデータが存在しません\n", key);
			}
		}
		else	/* ベスト10表示 */
		{
			sort_score(array, i);
			for (j = 0; j < 10; j++)
			{
				printf("順位：%d位\t学生番号：%d\t氏名：%s\t成績：%d\n", j+1, array[j].id, array[j].name, array[j].score);
			}
		}
    }
    

    /* 配列削除 */
    free(array);
    
    return 1;
}


