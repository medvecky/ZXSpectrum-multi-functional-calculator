#include <stdio.h>
#include <conio.h>

#include "modules/system_helper.h"
#include "modules/misc_helper.h"

int main( void )
{
    char argumentString[ MAX_INPUT_LENGTH ];
    char quitFlag = ' ';

    setUpScreen();

    header();

    getUserInput( argumentString );

    while ( quitFlag != 'q' )
    {
        handleArgumentString( argumentString );
        
        getUserInput( argumentString );

        quitFlag = argumentString[ 0 ];
    } 

    resetDefaultScreen();

    return EXIT_SUCCESS;
}
