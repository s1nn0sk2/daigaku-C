#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personal.h"


void ExchangeOfValues( struct personal_data_format *x , struct personal_data_format *y );


void QuickSort( struct personal_data_format *ary , int first_index , int last_index )
{
    int j;
    int ladd;

    if ( first_index < last_index )
    {
        ExchangeOfValues( (ary + first_index) , (ary + ( first_index + last_index ) / 2) );
        for ( j = first_index + 1 , ladd = first_index ; j <= last_index ; j++ )
        {
            if ( ( ary + first_index )->score < ( ary + j )->score )
            {
                ladd++;
                ExchangeOfValues( (ary + ladd) , (ary + j) );
				
            }
        }
        ExchangeOfValues( (ary + ladd) , (ary + first_index) );
        QuickSort( ary , first_index , ladd - 1 );
        QuickSort( ary , ladd + 1 , last_index );
    }

}

void ExchangeOfValues( struct personal_data_format  *x , struct personal_data_format  *y )
{
    struct personal_data_format tmp;

    tmp = *x;
	*x = *y;
    *y = tmp;
}

