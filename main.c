#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personal.h"

extern  struct personal_data_format *Data;
extern  int Data_num;

void InputFile( void );
int Attest( void );
void MakeSortData( struct personal_data_format *sort_data );
void QuickSort( struct personal_data_format *ary , int first_index , int last_index );
void ExchangeOfValues( struct personal_data_format *x , struct personal_data_format *y );
void OutputFile( struct personal_data_format *sort_data );

void main(void)
{
    struct personal_data_format *sort_data;
    int k;

    if ( (Data = calloc( 100, sizeof( struct personal_data_format ) )) == NULL)
    {
        printf("Not allocate memory !\n");
	    exit(1);
    }
    if ( (sort_data = calloc( 100, sizeof( struct personal_data_format ) )) == NULL)
    {
	    printf("Not allocate memory !\n");
	    exit(1);
    }

    InputFile();

    if ( (k = Attest()) == 1 )
    {
	    printf("Error ! \n");
        exit(1);
    }
    else if (k == 0)
    {
	    printf("Welcome ! \n");

    }

    MakeSortData( sort_data );

    QuickSort( sort_data , 0 , Data_num - 1 );

    OutputFile( sort_data );

    free( Data );
    free( sort_data );
}


