#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "11-12node.h"

struct score_node *make_list( FILE *fp)
{
struct score_node *head,*p;
char str[300],*p_str;


head=NULL;
while(fgets(str,256,fp)!=NULL){
	p=(struct score_node*)malloc(sizeof(struct score_node));
	p_str=strtok(str," \n");
	p->no=atoi(p_str);
	p_str=strtok(NULL," \n");
	strcpy(p->name,p_str);
	p_str=strtok(NULL," \n");
	p->score=atoi(p_str);
    p->next=head;
	head=p;
}
return head;
}

