#include <stdint.h>

#include "math_helper.h"

uint8_t argLength = 0;
float arg1Fp = 0.0;
float arg2Fp = 0.0;
float resultFp = 0.0;  

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
    if ( arg1Fp < 0 )
    {
        arg1Fp *= -1;
        resultFp = pow( arg1Fp, arg2Fp );

        if ( ( int )arg2Fp % 2 != 0 )
        {
            resultFp *= -1;
        }
    }
    else
    {
        resultFp = pow( arg1Fp, arg2Fp );
    }
}

void FP_abs( void )
{
   resultFp = fabs( arg1Fp );
}

void FP_atn( void )
{
    resultFp = atan( arg1Fp );
}

void FP_cos( void )
{
    resultFp = cos( arg1Fp );
}

void FP_mul10( void )
{
    resultFp = arg1Fp * 10;
}

void FP_div10( void )
{
    resultFp = arg1Fp / 10;
}

void FP_exp( void )
{
    resultFp = exp( arg1Fp );
}

void FP_int( void )
{
    resultFp = floor( arg1Fp );
}

void FP_log( void )
{
    resultFp = log( arg1Fp );
}

void FP_neg( void )
{
    resultFp = -arg1Fp;
}

void FP_sin( void )
{
    resultFp = sin( arg1Fp );
}

void FP_sqr( void )
{
    resultFp = pow( arg1Fp, 0.5 );
}

void FP_tan( void )
{
    resultFp = tan( arg1Fp );
}

void FP_sgn( void )
{
    resultFp = ( arg1Fp > 0 ) - ( arg1Fp < 0 );
}
