#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personal.h"

extern  int Data_num;

void OutputFile( struct personal_data_format *sort_data )
{
    FILE *fp;
    int i = 0;

    if( ( fp = fopen( "output.txt", "w" ) ) == NULL )
    {
        exit(1);
    }

    for( i = 0; i < Data_num; i++ )
    {
        fprintf( fp, "%s:%d\n", ( sort_data + i )->name, ( sort_data + i )->score );
    }

    fclose( fp );
}

