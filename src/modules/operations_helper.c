#include <stdlib.h>
#include <stdio.h>

#include "operations_helper.h"
#include "adt_stack.h"
#include "math_helper.h"

extern StackNodePtr stackPtr;
extern double resultFp;
extern double arg1Fp;
extern double arg2Fp;

Operator operators[] = 
{
    { '+', FP_add },
    { '-', FP_subst },
    { '*', FP_mult },
    { '/', FP_div },
    { ( char ) 0x5e, FP_pwr },
    { NULL, NULL }  // End marker
};


int handleFpOperator( char * token )
{
    Operator * op = operators;
    char operator = token[ 0 ];

    for ( op; op->name != NULL; op++ ) 
    {
        if ( ( op->name == operator ) ) 
        {
            if ( handleTwoOperandOperation( op->func ) == EXIT_FAILURE ) 
            {
                break;
            }
            Stack_push( &stackPtr, resultFp );    
            return EXIT_SUCCESS;
        }
    }

    puts( "FP operator failure" );

    return EXIT_FAILURE;
}

int handleTwoOperandOperation( void ( *operation )( void ) ) 
{
    if ( Stack_pop( &stackPtr, &arg2Fp ) == EXIT_FAILURE ) 
    {
        return EXIT_FAILURE;
    }

    if ( Stack_pop( &stackPtr, &arg1Fp ) == EXIT_FAILURE ) 
    {
        return EXIT_FAILURE;
    }

    operation(); 

    return EXIT_SUCCESS;
}