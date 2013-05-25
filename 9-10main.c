#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "6-7-8rpoland.h"

int	stackgen(void);
void	polish(struct pval_tbl *priority_tbl, char *equation, char *r_poland);
void	priority_set(struct pval_tbl *priority_tbl);
void	value_set(FILE *fp, struct pval_tbl *priority_tbl);
int	eval(struct pval_tbl * priority_tbl, char *r_poland);

int main(void)
{
	FILE *fin1, *fin2;
	char	buf[100], equation[100], r_poland[100], value[100];
	struct pval_tbl	priority_tbl[256];
	int	eval_result;



	/* 四則演算式ファイル名を指定する */
	printf("四則演算式ファイル名を指定してください\n");

	if (gets(buf) == NULL)
	{
		fprintf(stderr, "入力ファイル名の指定時にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	}
	/* 四則演算式ファイルをオープン */ 
    	if((fin1 = fopen(buf, "r")) == NULL ) {
        	fprintf(stderr,"入力ファイルオープンエラー\n");
        	exit(EXIT_FAILURE);
	}

	/* 式の読み込み */
	if (fgets(equation, 100, fin1) == NULL)
	{
		fprintf(stderr,"式が読み込めません\n");
        	exit(EXIT_FAILURE);
	}

	/* 変数値ファイル名を指定する */
	printf("変数値ファイル名を指定してください\n");

	if (gets(buf) == NULL)
	{
		fprintf(stderr, "入力ファイル名の指定時にエラーが発生しました\n");
		exit(EXIT_FAILURE);
	}
	/* 変数値ファイルをオープン */
	if((fin2 = fopen(buf, "r")) == NULL ) {
        	fprintf(stderr,"入力ファイルオープンエラー\n");
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

	/* 変数値を優先順位表に記入 */
	value_set(fin2, priority_tbl);

	/* 通常の数式を逆ポーランド式に変換 */
	polish(priority_tbl, equation, r_poland);

	/* 逆ポーランド式に値を代入して評価 */
	eval_result = eval(priority_tbl, r_poland);
	
	printf("四則演算式：%s\n", equation);
	rewind(fin2);
	while(fgets(value, 100, fin2) != NULL)
	{
		printf("%s", value);
	}
	printf("四則演算式の解答：%d\n", eval_result);
	fclose(fin1);
	fclose(fin2);
	return 0;

}