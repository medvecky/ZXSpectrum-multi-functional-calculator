#include <stdio.h>
#include <conio.h> 

#include "misc_helper.h"

void header( void )
{
    gotoxy( 13, 0 );
    puts( "CALCULATOR" );
    gotoxy( 0, 2 );
    puts( "Enter an expression for RPN calculation" );
    puts( "or 'q' for exit" );
    puts( "" );
    puts( "" );
}

void getUserInput( char * argumentString )
{
    size_t len = 0;
    printf( "%s", ">: " );
    
    if ( fgets( argumentString, MAX_INPUT_LENGTH, stdin ) == NULL ) 
    {
        puts( "Error reading input" );
        cgetc();
        resetDefaultScreen();
        exit( EXIT_FAILURE );
    }

    len = strlen( argumentString );
    
    if ( len > 0 && argumentString[ len - 1 ] == '\n' ) 
    {
        argumentString[ --len ] = '\0';   
    }
}

void handleArgumentString( char * argumentString )
{
    printf( "data: [ %s ]\n", argumentString );
}