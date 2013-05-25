#include  "14-15personal.h"

int	bnry_search(struct personal_data *array, int num, int key)
{
	int pl=0,pr=num-1,pc;

	while(pl<=pr){
		pc=(pl+pr)/2;
		if(array[pc].id<key){
			pl=pc+1;
		}else if(array[pc].id>key){
			pr=pc-1;
		}else{
			return (pc);
		}
	}
	return (-1);

}