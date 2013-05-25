#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int search(int key, struct student *array, int num_student);

int main(void)
{
    FILE *fin;
    int i, num_student, key, index;
	char buf[500], temp[50];
	struct student array[10];	//学生情報のデータ構造
	
	
	printf(" 2012年度第2回S課題1 \n");

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

    	/* 入力ファイルから1行読み込み */
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

	/* 学生番号指定 */
	printf("学生番号を入力してください\n");
	if (gets(buf) == NULL)
	{
		printf("学生番号の指定時にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	} 
	/* キーボードから整数以外を入力した場合はkeyに0が設定される */
	key = atoi(buf);

	
	/* 探索関数searchをコール */
	index = search(key, array, num_student);

	/* 学生名を表示 */
	if (index >= 0)
	{
		printf("学生番号%dの学生名は%sです\n", key, array[index].name);
	}
	else
	{
		printf("学生番号%dの学生は存在しません\n", key);
	}
    fclose(fin);

	return 0;
}
