#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "operations_helper.h"
#include "adt_stack.h"
#include "math_helper.h"
#include "stack_helper.h"
#include "history_helper.h"

extern StackNodePtr stackPtr;
extern float resultFp;
extern float arg1Fp;
extern float arg2Fp;

Operator operators[] = 
{
    { '+', FP_add },
    { '-', FP_subst },
    { '*', FP_mult },
    { '/', FP_div },
    { ( char ) 0x5e, FP_pwr },
    { NULL, NULL }  // End marker
};

Operation operations[] = 
{
    { "fabs", FP_abs },
    { "fatn", FP_atn },
    { "fcos", FP_cos },
    { "fmul10", FP_mul10 },
    { "fdiv10", FP_div10 },
    { "fexp", FP_exp },
    { "fint", FP_int },
    { "flog", FP_log },
    { "fneg", FP_neg },
    { "fsin", FP_sin },
    { "fsqr", FP_sqr },
    { "ftan", FP_tan },
    { "fsgn", FP_sgn },
    { NULL, NULL }  // End marker
};

Operation stackOperations[] = 
{
    { "ss", printStack },
    { "sc", clearStack },
    { "spop", popfromStack },
    { "sdupe", dupeStack },
    { "sswap", swapStack },
    { NULL, NULL }  // End marker
};

Operation historyOperations[] = 
{
    { "hs", printHistory },
    { "hel", historyGetLastElement },
    { "hc", clearHistory },
    { "hdl", deleteLastHiostryElement }, 
    { "hen", historyGetNthElement },
    // { "hee", historyEditAndExecute },
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

int handleFunction( char * token )
{  
    Operation * op = operations;

    for ( op; op->name != NULL; op++ ) 
    {
        if ( strcmp( token, op->name ) == 0 )  
        {
            handleOneOperandOperation( op->func );
            Stack_push( &stackPtr, resultFp ); 
            return EXIT_SUCCESS;
        }
    }
   
    puts( "Invalid function" );
   
    return EXIT_FAILURE;
}

void handleOneOperandOperation( void ( *operation )( void ) ) 
{
    Stack_pop(&stackPtr, &arg1Fp);
    operation(); 
}

int handleStackFunction( char * token )
{
    Operation * op = stackOperations;

    for ( op; op->name != NULL; op++ ) 
    {
        if ( strcmp( token, op->name ) == 0 )  
        {
            op->func();
            return EXIT_SUCCESS;
        }
    }
    
    puts( "Invalid stack function" );

    return EXIT_FAILURE;
}

int handleHistoryFunction( char * token )
{
    Operation * op = historyOperations;

    for ( op; op->name != NULL; op++ ) 
    {
        if ( strcmp( token, op->name ) == 0 )  
        {
            op->func();
            return EXIT_SUCCESS;
        }
    }
    
    puts( "Invalid history function" );

    return EXIT_FAILURE;
}