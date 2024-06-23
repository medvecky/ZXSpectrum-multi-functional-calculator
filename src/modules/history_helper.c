
#include <conio.h>
#include <stdio.h>

#include "adt_queue.h"
#include "misc_helper.h"

extern Queue * queuePtr;
extern size_t yPosition;
extern int isNeedToCorrectPosition;

static void editHistoryEntry( char * entryString );
static void cursorHandler( size_t cursorYPosition, char * entryString );
static void rewriteString( char * entryString, size_t currentCursorPosition );
static void handleBackspace( char * entryString, size_t * cursorYPosition, size_t * currentCursorPosition );

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
    size_t cursorYPosition = 0;
   
    printf( "%s]", entryString );
    cursorYPosition = wherey();
    
    cursorHandler( cursorYPosition, entryString );
}

// TODO: ADD handling of adding characters to the string
// TODO: use apropriate int type in new functions

static void cursorHandler( size_t cursorYPosition, char * entryString )
{
    char currentKey = cgetc();
    size_t entryLength = strlen( entryString );   
    size_t currentCursorPosition = entryLength - 2;

    if ( entryLength > 41) cursorYPosition--;

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

        case 0x0c:
            handleBackspace( entryString, &cursorYPosition,  &currentCursorPosition );
            break;
        
        default:
            break;
        }

        gotoxy( 0, cursorYPosition );
        rewriteString( entryString, currentCursorPosition );
        currentKey = cgetc();
        entryLength = strlen( entryString ); 
    }

     gotoxy( 0, cursorYPosition );
     printf( "%s  ", entryString );

}

static void rewriteString( char * entryString, size_t currentCursorPosition )
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
    
    if ( entryLength <= 0 ) 
    {
        printf( "%s","]     " );
    }
    else
    {
         printf( "%s", "     "  );
    }
}

static void handleBackspace( char * entryString, size_t * cursorYPosition, size_t * currentCursorPosition )
{
    size_t entryLength = strlen( entryString );
    if ( *currentCursorPosition < entryLength ) 
    {
        memmove( &entryString[ *currentCursorPosition ], &entryString[ *currentCursorPosition + 1], entryLength - *currentCursorPosition );
        if ( *currentCursorPosition > 0 ) ( *currentCursorPosition )--;
    }
}