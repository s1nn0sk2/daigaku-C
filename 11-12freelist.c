#include <stdlib.h>
#include "11-12node.h"

void free_list(struct score_node *head)
{
	struct score_node *s;

	while(head!=NULL){
		s=head;
		head=head->next;
		free(s);
 }
}
