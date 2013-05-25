#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "11-12node.h"

extern struct score_node *Hash_tbl[11];
int	hash_func(char *name);


int	make_tbl( FILE *fp)
{
	struct score_node *p;
    char str[300],*p_str;
	int i;

    while(fgets(str,256,fp)!=NULL){
	if((p=(struct score_node*)malloc(sizeof(struct score_node)))==NULL){
		return (-1);
	}
	p_str=strtok(str," \n");
	p->no=atoi(p_str);
	p_str=strtok(NULL," \n");
	strcpy(p->name,p_str);
	p_str=strtok(NULL," \n");
	p->score=atoi(p_str);
	i=hash_func(p->name);
	p->next=Hash_tbl[i];
	Hash_tbl[i]=p;
    
	
  }
	return(0);

}

