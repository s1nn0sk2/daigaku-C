#include <stdio.h>
#include <stdlib.h>
#include "6-7-8rpoland.h"

extern struct stack Stack_header;

int	stackgen()
{
	Stack_header.max_num=100;
	Stack_header.ptr=0;
	Stack_header.stk=(int *)calloc(Stack_header.max_num,sizeof(struct stack));
	if(Stack_header.stk==NULL){
		return -1;
	}else{
		return 0;
	}


}