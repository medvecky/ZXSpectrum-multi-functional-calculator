#ifndef ATD_STACK_H
#define ATD_STACK_H

#include <stdbool.h>

struct stackNode
{
    double data;
    struct stackNode *nextPtr; 
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void Stack_push( StackNodePtr * topPtr, double value );
void Stack_print( StackNodePtr currentPtr );
int Stack_pop( StackNodePtr * topPtr, double * popValue );
bool Stack_isEmpty( StackNodePtr topPtr );
void Stack_getTop( StackNodePtr topPtr, double * topValue );
void Stack_free( StackNodePtr * topPtr );
void Stack_dupe( StackNodePtr * topPtr );
void Stack_swap( StackNodePtr * topPtr );

#endif