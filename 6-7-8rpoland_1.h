/* �\����stack���`���Ă������� */
struct stack
{
	int max_num;
	int ptr;
	int *stk;
};
struct stack Stack_header;
/* �\����pval_tbl���`���Ă������� */
struct pval_tbl
{
	int priority;
	int value;
};
