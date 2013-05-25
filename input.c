#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "personal.h"

extern  struct personal_data_format *Data;
extern  int Data_num;


void InputFile( void )
{
    FILE *fp;
    char str[256];
    char *p_str;
    int i = 0;

    if( ( fp = fopen( "input.data", "r" ) ) == NULL )
    {
        exit(1);
    }

    while( fgets( str, 256, fp ) != NULL )
    {
        p_str = strtok( str, " ,\n" );
        strcpy( ( Data + i )->name, p_str );
        p_str = strtok( NULL, " ,\n" );
        strcpy( ( Data + i )->pass, p_str );
        p_str = strtok( NULL, " ,\n" );
        ( Data + i )->score = atoi( p_str );

        i++;
    }

    Data_num = i;
    fclose( fp );
}

