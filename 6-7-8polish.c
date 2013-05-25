#include <stdio.h>
#include <stdlib.h>
#include "6-7-8rpoland.h"

void	push(int n);
int	pop(void);
int	stacktop(void);

extern struct stack Stack_header;

void	polish(struct pval_tbl *priority_tbl, char *equation, char *r_poland)
{
	int i=0,j=0;
	do{
	while(equation[i]!=NULL){
		if(equation[i]=='('){
			push(equation[i]);
		}
		else if(equation[i]==')'){
			while(stacktop()!='('){
				r_poland[j]=pop();
			j++;
			}
			pop();
		}else{
			while(priority_tbl[equation[i]].priority<=priority_tbl[stacktop()].priority){
			r_poland[j]=pop();
			j++;
		}
		push(equation[i]);
	   }
		i++;
	 }
	    if(stacktop()!=-1){
			r_poland[j]=pop();
	        j++;
		}
	}while(stacktop()!=-1);
	r_poland[j]='\0';

}
void	push(int n)
{
	int	i;

	if (Stack_header.ptr >= Stack_header.max_num)
	{
		printf("stack overflow\n");
		exit(1);
	}
	i = Stack_header.ptr;
	Stack_header.stk[i] = n;
	Stack_header.ptr++;
}

int	pop(void)
{
	int	i;

	if (Stack_header.ptr < 1)
	{
		printf("stack underflow\n");
		exit(1);
	}
	i = Stack_header.ptr-1;
	Stack_header.ptr--;
	return Stack_header.stk[i];
}

int	stacktop(void)
{
	if (Stack_header.ptr == 0)
	{
		return -1;
	}
	return Stack_header.stk[Stack_header.ptr-1];
}