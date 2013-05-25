#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personal.h"


extern  struct personal_data_format *Data;
extern  int Data_num;


void MakeSortData( struct personal_data_format *sort_data )
{
    int i;

    for( i =0; i < Data_num; i++ )
    {
        strcpy( ( sort_data + i )->name, ( Data + i )->name );
        ( sort_data + i )->score = ( Data + i )->score;
    }
}

