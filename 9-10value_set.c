#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "6-7-8rpoland.h"

void	value_set(FILE *fp, struct pval_tbl *priority_tbl)
{
  char str[300],*p,*q;
  while(fgets(str,256,fp)!=NULL){
	  p=strtok(str,"=\n");
	  q=strtok(NULL,"=\n");
	  priority_tbl[*p].value=atoi(q);
 }
}