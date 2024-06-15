#include <stdio.h>
#include <stdlib.h>


#include "adt_stack.h"

void Stack_push( StackNodePtr * topPtr, double value )
{
    StackNodePtr newPtr;

    newPtr = malloc( sizeof( StackNode ) );
    
    if ( newPtr != NULL )
    {
        newPtr->data = value;
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    } 
    else 
    {
        printf( "[STACK]: [%f] not inserted. No memory available.\n", value );
    } 
}  

void Stack_print( StackNodePtr currentPtr )
{
    if ( currentPtr == NULL )
    {
        puts( "[STACK]: Empty" );
    } 
    else
    {
        puts( "--> stack's top <--" );
        while ( currentPtr != NULL ) 
        {
            printf( "[ %f ]\n", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
        } 
        puts( "--> stack's bottom <--" );
    }   
} 

int Stack_pop( StackNodePtr * topPtr, double * popValue )
{
    StackNodePtr tempPtr;

    if ( Stack_isEmpty( *topPtr ) ) 
    {
        puts( "[STACK]: Empty" );
        return EXIT_FAILURE;
    }

    tempPtr = *topPtr;
    *popValue = ( *topPtr )->data;
    *topPtr = ( *topPtr )->nextPtr;
    free( tempPtr );

    return EXIT_SUCCESS;
} 

bool Stack_isEmpty( StackNodePtr topPtr )
{
    return topPtr == NULL;
} 

void Stack_getTop( StackNodePtr topPtr, double * topValue)
{
    if ( Stack_isEmpty( topPtr ) ) 
    {
        puts( "[STACK]: Empty" );
        return;
    }

    double * topValue = &topPtr->data;
} 

void Stack_free( StackNodePtr * topPtr )
{
    StackNodePtr tempPtr;

    while ( *topPtr != NULL )
    {
        tempPtr = *topPtr;
        *topPtr = ( *topPtr )->nextPtr;
        free( tempPtr );
    }   
}

void Stack_dupe( StackNodePtr * topPtr )
{
    double topValue;

    if ( Stack_isEmpty( *topPtr ) )
    {
        puts( "[STACK]: Empty" );
        return;
    }
 
    Stack_getTop( *topPtr, &topValue );
    Stack_push( topPtr, topValue );
}

void Stack_swap( StackNodePtr * topPtr )
{
    double topValue;
    double secondValue;

    if ( Stack_isEmpty( *topPtr ) )
    {
        puts( "[STACK]: Empty" );
        return;
    }

    Stack_pop( topPtr, &topValue );

    if ( Stack_isEmpty( *topPtr ) )
    {
        Stack_push( topPtr, topValue );
        return;
    }

    Stack_pop( topPtr, &secondValue );
    Stack_push( topPtr, topValue );
    Stack_push( topPtr, secondValue );
}