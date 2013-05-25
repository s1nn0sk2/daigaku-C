#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "14-15personal.h"


void make_array(FILE *fp, struct personal_data *array)
{

    char str[300],*p_str;
	int i=0;

    while(fgets(str,256,fp)!=NULL){

	p_str=strtok(str," \n");
	array[i].id=atoi(p_str);
	p_str=strtok(NULL," \n");
	strcpy(array[i].name,p_str);
	p_str=strtok(NULL," \n");
	array[i].score=atoi(p_str);
	i++;
	
  }

}






