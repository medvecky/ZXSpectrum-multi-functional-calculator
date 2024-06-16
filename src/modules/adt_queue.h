#ifndef   ADT_QUEUE_H  
#define   ADT_QUEUE_H

#include <stddef.h>

#define MAX_QUEUE_SIZE 5

typedef struct Node 
{
    char * data;        // Data field is now a pointer to a character (string)
    struct Node * next;
} Node;

typedef struct Queue 
{
    Node * head;
    Node * tail;
    size_t size;          // Track the size of the queue
    size_t capacity;      // Maximum capacity of the queue
} Queue;

Queue * Queue_create( size_t capacity );
void Queue_print( Queue * q );
void Queue_enqueue( Queue * q, const char * value );
char * Queue_getLastElement( Queue * q );
void Queue_clear( Queue * q );
void Queue_deleteLastElement( Queue * q );
size_t Queue_getSize( Queue * q );
char * Queue_getNthElement( Queue * q, size_t n );
void Queue_print_raw( Queue * q );

#endif