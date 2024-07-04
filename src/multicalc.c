#include <stdio.h>
#include <conio.h>

#include "modules/system_helper.h"
#include "modules/misc_helper.h"
#include "modules/adt_queue.h"

Queue * queuePtr = NULL;

int main( void )
{
    char argumentString[ MAX_INPUT_LENGTH ];
    char quitFlag = ' ';
    queuePtr = Queue_create( MAX_QUEUE_SIZE );

    setUpScreen();

    header();

    getUserInput( argumentString );
    quitFlag = argumentString[ 0 ];

    while ( quitFlag != 'q' )
    {
        handleArgumentString( argumentString );
        
        getUserInput( argumentString );
        quitFlag = argumentString[ 0 ];
    } 

    return EXIT_SUCCESS;
}
