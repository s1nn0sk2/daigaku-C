#include <stdio.h>
#include <string.h>
#include "11-12node.h"

struct score_node	*search_node(char *name, struct score_node *head)
{
	struct score_node *ptr;


	ptr=head;
	while(ptr!=NULL){
		if(strcmp(ptr->name,name)!=0){
			ptr=ptr->next;
		}else{
			return ptr;
		}
	}
	return NULL;
}