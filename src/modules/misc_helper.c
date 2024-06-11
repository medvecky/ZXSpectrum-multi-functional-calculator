#include <stdio.h>
#include <conio.h> 

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