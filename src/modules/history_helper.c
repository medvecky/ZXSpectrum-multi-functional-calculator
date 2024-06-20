
#include <conio.h>
#include <stdio.h>

#include "adt_queue.h"
#include "misc_helper.h"

extern Queue * queuePtr;
extern size_t yPosition;
extern int isNeedToCorrectPosition;

static void editHistoryEntry( char * entryString );
static void cursorHandler( int cursorYPosition, char * entryString );
static void rewriteString( char * entryString, int currentCursorPosition );

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
    puts( "" );

    if ( nthElement != NULL ) 
    {
        handleArgumentString( nthElement );
    }
}

static void editHistoryEntry( char * entryString )
{
    int cursorXPosition = 0;
    int cursorYPosition = 0;
   
    printf( "%s]", entryString );
    cursorXPosition = wherex();
    cursorYPosition = wherey();
    
    cursorHandler( cursorYPosition, entryString );
}

// TODO: ADD handling of deleting characters from the string
// TODO: ADD handling of adding characters to the string
// TODO: ADD hadling of long strings that does not fit the screen

static void cursorHandler( int cursorYPosition, char * entryString )
{
    char currentKey = cgetc();
    size_t entryLength = strlen( entryString );
    int currentCursorPosition = entryLength - 2;

    while ( currentKey != 0x0a )
    {
        switch ( currentKey )
        {
        case 0x08:
            if ( currentCursorPosition > 0 )
            {
                currentCursorPosition--;
            }
            break;
        
        case 0x09:
            if ( currentCursorPosition < entryLength - 1 )
            {
                currentCursorPosition++;
            }
            break;
        
        default:
            break;
        }

        gotoxy( 0, cursorYPosition );
        rewriteString( entryString, currentCursorPosition );
        currentKey = cgetc();
    }
}

static void rewriteString( char * entryString, int currentCursorPosition )
{
    size_t index = 0;
    size_t entryLength = strlen( entryString );

    for ( index = 0; index < entryLength; index++ )
    {
        if ( index == currentCursorPosition )
        {
            printf( "%c]", entryString[ index ] );
        }
        else
        {
            printf( "%c", entryString[ index ] );
        }
    }
}