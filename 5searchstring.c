#include "3personal.h"
#include <string.h>

int	searchstring(struct personal_data *array, int num_student, char *string){
	/* プログラミングしてください */
	int i;
	for(i=0;i<num_student;i++){
		if(strcmp(string,array[i].name)==0){
			return i;
		}
	}
	return -1;


}