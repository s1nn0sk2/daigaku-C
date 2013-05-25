#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "6-7-8rpoland.h"

void	push(int n);
int	pop(void);

int	eval(struct pval_tbl * priority_tbl, char *r_poland)
{
	char *s;
	int d1,d2;


	s=r_poland;
	while(*s!=NULL){
		if(*s=='+'){
			d1=pop();
			d2=pop();
			push(d2+d1);
		}else if(*s=='-'){
			d1=pop();
			d2=pop();
			push(d2-d1);
		}else if(*s=='*'){
			d1=pop();
			d2=pop();
			push(d2*d1);
		}else if(*s=='/'){
			d1=pop();
			d2=pop();
			push(d2/d1);
		}else{
			push(priority_tbl[*s].value);
		}
	s++;
	}
	return(pop());		
}