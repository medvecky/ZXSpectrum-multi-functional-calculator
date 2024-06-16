#include <stdio.h>

#include "adt_stack.h"
#include "system_helper.h"

extern StackNodePtr stackPtr;
extern float resultFp;

void printStack( void )
{
    Stack_print( stackPtr );
}

void clearStack( void )
{
    Stack_free( &stackPtr );
}

void popfromStack( void )
{
    Stack_pop(&stackPtr, &resultFp);
    printf( "%f\n", resultFp );
}

void dupeStack( void )
{
    Stack_dupe( &stackPtr );
}

void swapStack( void )
{
    Stack_swap( &stackPtr );
}