#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "6-7-8rpoland.h"

int	stackgen(void);
void	polish(struct pval_tbl *priority_tbl, char *equation, char *r_poland);
void	priority_set(struct pval_tbl *priority_tbl);


int main(void)
{
	FILE *fin;
	char	buf[100], equation[100], r_poland[100];
	struct pval_tbl	priority_tbl[256];


	printf("2012年度　第6・7・8回アルゴリズムとデータ構造演習(S)課題\n");

	/* 入力ファイル名を指定する */
	printf("入力ファイル名を指定してください\n");

	if (gets(buf) == NULL)
	{
		fprintf(stderr, "入力ファイル名の指定時にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	}
	/* 入力ファイルをオープン */ 
    	if((fin = fopen(buf, "r")) == NULL ) {
        	fprintf(stderr,"入力ファイルオープンエラー\n");
        	exit(EXIT_FAILURE);
	}

	/* 式の読み込み */
	if (fgets(equation, 100, fin) == NULL)
	{
		fprintf(stderr,"式が読み込めません\n");
        	exit(EXIT_FAILURE);
	}


	/* スタック生成 */
	if (stackgen() == -1)
	{
		fprintf(stderr, "スタックの生成に失敗しました\n");
		exit(EXIT_FAILURE);
	}

	/* 優先順位表作成 */
	priority_set(priority_tbl);

	/* 通常の数式を逆ポーランド式に変換 */
	polish(priority_tbl, equation, r_poland);

	/* 逆ポーランド式を標準出力に出力 */
	printf("通常の式：%s\n", equation);
	printf("逆ポーランド式：%s\n", r_poland);
	fclose(fin);
	return 0;

}