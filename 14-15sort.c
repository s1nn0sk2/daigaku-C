#include  "14-15personal.h"

void sort_id(struct personal_data *array, int num)
{
	int i,j;
	struct personal_data p;


	for(i=0;i<=num-2;i++){
		for(j=num-1;j>i;j--){
			if(array[j-1].id>array[j].id){
				p=array[j-1];
				array[j-1]=array[j];
				array[j]=p;
			}
		}
}
}
void sort_score(struct personal_data *array, int num)
{
	int i,j;
	struct personal_data p;
	

 for(i=0;i<=num-2;i++){
	 for(j=num-1;j>i;j--){
		 if(array[j-1].score<array[j].score){
			 p=array[j-1];
			 array[j-1]=array[j];
			 array[j]=p;

		 }
	 }
 }

}