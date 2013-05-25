#include <stdlib.h>
#include <stdio.h>
#include "11-12node.h"

extern struct score_node *Hash_tbl[11];

void free_tbl()
{ 
	int i;
	struct score_node *p;

	for(i=0;i<11;i++){
		while(Hash_tbl[i]!=NULL){
			p=Hash_tbl[i];
			Hash_tbl[i]=Hash_tbl[i]->next;
			free(p);
		}
   }
}