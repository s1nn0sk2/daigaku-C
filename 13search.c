#include <stdio.h>
#include <string.h>
#include "11-12node.h"

int	hash_func(char *name);
extern struct score_node *Hash_tbl[11];

/* 個人成績データ探索 */
struct score_node *search_node(char *name)
{
	struct score_node *ptr;
	int i;

	i=hash_func(name);
	ptr=Hash_tbl[i];

	while(ptr!=NULL){
		if(strcmp(ptr->name,name)==0){
		return (ptr);
		}else{
			ptr=ptr->next;
		}
  }
return NULL;
}