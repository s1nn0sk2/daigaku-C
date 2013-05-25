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


	printf("平成24年度第3回アルゴリズムとデータ構造演習(S)\n");
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
	
	/* 学生数を指定する */
	
	while (1)
	{
		printf("学生数を指定してください\n");
		if (gets(buf) == NULL)
		{
			printf("入力ファイル名の指定時にエラーが発生しました\n");
			exit(EXIT_FAILURE);
		}
		num_student = atoi(buf);
		if (num_student == 0)
		{
			printf("指定された学生数が違います！1以上の整数を入力してください！\n");
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
	printf("正常に終了しました。\n");
	printf("output.txtファイルをオープンして配列arrayのデータを確認ください\n");
	return 0;
}


