#include <stdint.h>

#include "math_helper.h"

uint8_t argLength = 0;
double arg1Fp = 0.0;
double arg2Fp = 0.0;
double resultFp = 0.0;  

char arg1[ MAX_ARGUMENT_LENGTH ];
char arg2[ MAX_ARGUMENT_LENGTH ];

void FP_add( void )
{
    resultFp = arg1Fp + arg2Fp;
}

void FP_subst( void )
{
    resultFp = arg1Fp - arg2Fp;
}

void FP_mult( void )
{
    resultFp = arg1Fp * arg2Fp;
}

void FP_div( void )
{
    resultFp = arg1Fp / arg2Fp;
} 

void FP_pwr( void )
{
    resultFp = pow( arg1Fp, arg2Fp );
}
