#include <ctype.h>
#include "6-7-8rpoland.h"

void	priority_set(struct pval_tbl *priority_tbl)
{
	int i;
	for(i=0;i<255;i++){
		if(isalpha(i)!=0){
			priority_tbl[i].priority=3;
		}else{
			priority_tbl[i].priority=-1;
		}

	priority_tbl['*'].priority=2;
	priority_tbl['/'].priority=2;
	priority_tbl['+'].priority=1;
	priority_tbl['-'].priority=1;
	priority_tbl['('].priority=0;

	
 
 }
}