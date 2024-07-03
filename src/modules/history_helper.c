
#include <conio.h>
#include <stdio.h>
#include <cpm.h>

#include "adt_queue.h"
#include "misc_helper.h"
#include "history_helper.h"
#include "system_helper.h"

extern Queue * queuePtr;
extern size_t yPosition;
extern int isNeedToCorrectPosition;

static void editHistoryEntry( char * entryString );
static void cursorHandler( size_t cursorYPosition, char * entryString );
static void rewriteString( char * entryString, size_t currentCursorPosition );
static void handleBackspace( char * entryString, size_t * cursorYPosition, size_t * currentCursorPosition );
static void handleSymbolInput( char * entryString, size_t * cursorYPosition,  size_t * currentCursorPosition, char currentKey ); 

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

#ifdef __CPM__
    cls();
#else       
    clrscr();
#endif

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

#ifdef __CPM__
    cursorYPosition = a_cury();
#else
    cursorYPosition = wherey();
#endif
    
    cursorHandler( cursorYPosition, entryString );
}

static void cursorHandler( size_t cursorYPosition, char * entryString )
{
    char currentKey = cgetc();
    size_t entryLength = strlen( entryString );   
    size_t currentCursorPosition = entryLength - 1;

    if ( entryLength > SCREEN_WIDTH && cursorYPosition < SCREEN_HEIGHT )
    {
        cursorYPosition++;
    }
    { 
        cursorYPosition--;
    }

    while ( currentKey != 0x0a )
    {
        switch ( currentKey )
        {
#ifdef __CPM__
        case 0x01:
#else
        case 0x08:
#endif
            if ( currentCursorPosition > 0 )
            {
                currentCursorPosition--;
            }
            break;
#ifdef __CPM__
        case 0x06:
#else        
        case 0x09:
#endif
            if ( currentCursorPosition < entryLength - 1 )
            {
                currentCursorPosition++;
            }
            break;
#ifdef __CPM__
        case 0x08:
#else   
        case 0x0c:
#endif        
            handleBackspace( entryString, &cursorYPosition,  &currentCursorPosition );
            break;
        
        CASE_HEX_0x02A_TO_0x039:
        CASE_HEX_0x041_TO_0x05A:
        CASE_HEX_0x05E:
        CASE_HEX_0x061_TO_0x07A:
            handleSymbolInput( entryString, &cursorYPosition, &currentCursorPosition, currentKey );
            break;
        
        default:
            break;
        }
#ifdef __CPM__ 
        gotoyx( cursorYPosition, 0 );
#else               
        gotoxy( 0, cursorYPosition );
#endif
        rewriteString( entryString, currentCursorPosition );
        currentKey = cgetc();
        entryLength = strlen( entryString );
    }

#ifdef __CPM__ 
    gotoyx( cursorYPosition, 0 );
#else
     gotoxy( 0, cursorYPosition );
#endif
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
    if ( *currentCursorPosition < entryLength && entryLength > 1 ) 
    {
        memmove( &entryString[ *currentCursorPosition ], &entryString[ *currentCursorPosition + 1], entryLength - *currentCursorPosition );
        if ( *currentCursorPosition > 0 ) ( *currentCursorPosition )--;
    }
}

static void handleSymbolInput( char * entryString, size_t * cursorYPosition,  size_t * currentCursorPosition, char currentKey )
{
    size_t entryLength = strlen( entryString );
     ( *currentCursorPosition ) += 1;

    if ( entryLength < MAX_INPUT_LENGTH - 1 )
    {
        memmove( &entryString[ *currentCursorPosition + 1 ], &entryString[ *currentCursorPosition ], entryLength - *currentCursorPosition + 1 );
        entryString[ *currentCursorPosition ] = currentKey;
    }
}