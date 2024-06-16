#ifndef OPERATIONS_HELPER_H
#define OPERATIONS_HELPER_H

typedef void ( *OperationFunc )( void );

typedef struct 
{
    char name;
    OperationFunc func;
} Operator;

typedef struct 
{
    char * name;
    OperationFunc func;
} Operation;


int handleFpOperator( char * token );
int handleFunction( char * token );
int handleStackFunction( char * token );
// int handleHistoryFunction( char * token );
int handleTwoOperandOperation( void ( *operation )( void ) );
void handleOneOperandOperation( void ( *operation )( void ) );

#endif