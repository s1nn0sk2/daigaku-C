/* 構造体stackを定義してください */
struct stack
{
	int max_num;
	int ptr;
	int *stk;
};
struct stack Stack_header;
/* 構造体pval_tblを定義してください */
struct pval_tbl
{
	int priority;
	int value;
};
