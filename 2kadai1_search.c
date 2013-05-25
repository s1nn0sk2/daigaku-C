#include "data.h"

int search(int key, struct student *array, int num_student)
{
	int i;
 for(i=0;i<num_student;i++){
  if(array[i].number==key){
	  return i;
}
 }
return -1;
}


