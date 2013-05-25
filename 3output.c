#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "3personal.h"


void outputfile( struct personal_data *array, int num_student )
{
	int i;
    FILE *fo;
	fo=fopen("output.txt","w");
	
	
    i=0;
	for(i=0;i<num_student;i++){
	fprintf(fo,"array[%d].id=%d:array[%d].name=%s:array[%d].score=%d\n",i,array[i].id,i,array[i].name,i,array[i].score);
	
 }

 fclose(fo);
}