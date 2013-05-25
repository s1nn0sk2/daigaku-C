#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3personal.h"


void inputfile(FILE *fp, struct personal_data *array, int num_student)
{
 int i;
 char str[300],*p_str;
 fp=fopen("score.txt","r");
 

for(i=0;i<num_student;i++){
	if(fgets(str,256,fp)==NULL){
		break;
	}else{
	p_str=strtok(str," \n");
	array[i].id=atoi(p_str);
	p_str=strtok(NULL," \n");
	strcpy(array[i].name,p_str);
	p_str=strtok(NULL," \n");
	array[i].score=atoi(p_str);
	}
}
fclose(fp);
}