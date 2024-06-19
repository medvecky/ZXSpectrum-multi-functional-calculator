
#include <conio.h>
#include <stdio.h>

#include "adt_queue.h"
#include "misc_helper.h"

extern Queue * queuePtr;
extern size_t yPosition;
extern int isNeedToCorrectPosition;

static void editHistoryEntry( char * entryString );

void printHistory( void )
{
    Queue_print( queuePtr );
}

void historyGetLastElement( void )
{
    char * lastElement = Queue_getLastElement( queuePtr );
    
    if ( lastElement != NULL ) 
    {
        handleArgumentString( lastElement );
    }
}

void clearHistory( void )
{
    Queue_clear( queuePtr );
}

void deleteLastHiostryElement( void )
{
    Queue_deleteLastElement( queuePtr );
}

void historyGetNthElement( void )
{
    size_t n = 0;
    char * nthElement = NULL;

    size_t queueSize = Queue_getSize( queuePtr );

    Queue_print( queuePtr );

    n = cgetc() - '0';
    
    while ( n <= 0 || n > queueSize ) 
    {
        puts( "Invalid entry number" );
        n = cgetc() - '0';
    }

    nthElement = Queue_getNthElement( queuePtr, n );
    
    if ( nthElement != NULL ) 
    {
        handleArgumentString( nthElement );
    }
}

void historyEditAndExecute( void )
{
    size_t n = 0;
    char * nthElement = NULL;

    size_t queueSize = Queue_getSize( queuePtr );

    Queue_print_raw( queuePtr );

    n = cgetc() - '0';
    
    while ( n <= 0 || n > queueSize ) 
    {
        puts( "Invalid entry number" );
        n = cgetc() - '0';
    }

    nthElement = Queue_getNthElement( queuePtr, n );

    editHistoryEntry( nthElement );

    if ( nthElement != NULL ) 
    {
        handleArgumentString( nthElement );
    }
}

static void editHistoryEntry( char * entryString )
{
    printf( "%s", entryString );
    // TODO get cursor postion ( ASM or CP/M or something )
    // TODO implement cursor moving 
    // TDOD implement editing ( more subtasks )
    cgetc();
}

