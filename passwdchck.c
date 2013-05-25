#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personal.h"

extern  struct personal_data_format *Data;
extern  int Data_num;

int Attest( void )
{
    int i;
    char input_name[50];
    char input_pass[50];

    printf( "name:" );
    scanf( "%s", input_name );
    printf( "pass:" );
    scanf( "%s", input_pass );
    printf( "\n" );
    for( i = 0; i < Data_num; i++ )
    {
        if( strcmp( ( Data + i )->name, input_name ) == 0 )
        {
            if( strcmp( ( Data + i )->pass, input_pass ) == 0 )
            {

                return( 0 );
            }
        }
    }

    return( 1 );
}
