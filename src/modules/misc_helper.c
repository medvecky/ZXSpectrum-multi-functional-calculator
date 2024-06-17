#include <stdio.h>
#include <conio.h> 
#include <ctype.h>
#include <stdbool.h>

#include "misc_helper.h"
#include "system_helper.h"
#include "math_helper.h"
#include "adt_stack.h"
#include "operations_helper.h"
#include "adt_queue.h"
#include "history_helper.h"

StackNodePtr stackPtr = NULL;
bool isShowingResult = false;
int isNeedToClear = 0;

extern char arg1[ MAX_ARGUMENT_LENGTH ];
extern uint8_t argLength;
extern float arg1Fp;
extern float resultFp;
extern Queue * queuePtr;

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
        // resetDefaultScreen();
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
    char * token;
    char key = argumentString[ 0 ];

    if ( strcmp( argumentString, "4 8 15 16 23 42" ) == 0 ) 
    {
        puts( "\nYou saved the world again!\n" );
        puts( "I'll see you in another life, brother." );
        puts( "Keep heading towards Swan Station when\nyou're stuck in an everlasting summer\n" );
        
        return;
    }
    
    if ( key != 'h' && key != '\0' )
    {
        Queue_enqueue( queuePtr, argumentString );
    } 
    
    token = strtok( argumentString, " " );

    while ( token != NULL ) 
    {
        if ( handleToken( token ) == EXIT_FAILURE ) break;
        
        token = strtok( NULL, " " );
    }

    showResult();

    if ( isNeedToClear ) 
    {
        free( argumentString );
        isNeedToClear = 0;
    }
}

int handleToken( char * token )
{
    if ( isdigit( ( unsigned char )token[ 0 ] ) || 
            ( ( unsigned char )token[ 0 ]  == '-' && 
            isdigit( ( unsigned char )token[ 1 ] ) ) ) 
    {
        if  ( handleNumber( token ) == EXIT_FAILURE ) 
        {
            isShowingResult = false;
            return EXIT_FAILURE;
        }
    } 
    else 
    {
        if ( handleOperator( token ) == EXIT_FAILURE ) 
        {
            isShowingResult = false;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int handleNumber( char * token )
{
    if ( strlen( token ) >= sizeof( arg1 ) ) 
    {
        puts( "Number is too long" );
        return EXIT_FAILURE;
    }

    if ( !isValidNumber( token ) ) 
    {
        puts( "Invalid number format" );
        return EXIT_FAILURE;
    }
    
    strncpy( arg1, token, sizeof( arg1 ) - 1 );
    arg1[ sizeof( arg1 ) - 1 ] = '\0';

    argLength = strlen( arg1 );

    arg1Fp = atof( arg1 );

    Stack_push( &stackPtr, arg1Fp );

    return EXIT_SUCCESS;
}

int handleOperator( char * token )
{
    char operator = token[ 0 ];

    if ( Stack_isEmpty( stackPtr ) )
    {
        puts( "[handleOperator]: Stack is empty." );
        return EXIT_FAILURE;
    }
    else
    {
        switch ( operator )
        {
            case 'f':
                if ( handleFunction( token ) == EXIT_FAILURE ) 
                {
                    return EXIT_FAILURE;
                } 
                
                isShowingResult = true;
                break;
            
            case 's':
                if ( handleStackFunction( token ) == EXIT_FAILURE ) 
                {
                    return EXIT_FAILURE;
                }
                
                isShowingResult = false;
                break;

            case 'h':
                if ( handleHistoryFunction( token ) == EXIT_FAILURE ) 
                {
                    return EXIT_FAILURE;
                }
                
                isShowingResult = false;
                break;    
            
            default:
                if ( handleFpOperator( token ) == EXIT_FAILURE ) 
                {
                    return EXIT_FAILURE;
                }
                
                isShowingResult = true;
                break;
        }
    } 

    return EXIT_SUCCESS;
}

int isValidNumber( const char *str ) 
{
    size_t i = 0;

    for ( i = 0; str[ i ]; i++ ) 
    {
        if ( !isdigit( str[ i ] ) && str[ i ] != '-' && 
                str[ i ] != 'e' && str[ i ] != '.' ) 
        {
            return false;
        }
    }
    return true;
}

void showResult( void )
{
    if ( isShowingResult )
    {
        // if ( isNeedToCorrectPosition )
        // {
        //     gotoy( yPosition );
        //     puts( "" );
        //     isNeedToCorrectPosition = 0;
        // }
        
        if ( Stack_isEmpty( stackPtr ) )
        {
            puts( "Stack is empty [Show result]" );
        }
        else 
        {
            Stack_getTop( stackPtr, &resultFp );
            printf( "%f\n", resultFp );
        }
    }
}