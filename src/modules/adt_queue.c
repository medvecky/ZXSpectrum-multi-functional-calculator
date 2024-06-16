#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "adt_queue.h"

extern int isNeedToClear;

Queue * Queue_create( size_t capacity ) 
{
    Queue * q = ( Queue * )malloc( sizeof( Queue ) );
    q->head = q->tail = NULL;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void Queue_print( Queue * q ) 
{
    size_t index = 1;
    Node * current = q->head;
    
    while ( current != NULL ) 
    {
        printf( "%d. %s\n", index++, current->data );
        current = current->next;
    }
    
    puts( "" );
}

void Queue_print_raw( Queue * q ) 
{
    size_t index = 1;
    Node * current = q->head;
    
    while ( current != NULL ) 
    {
        puts( current->data );
        current = current->next;
    }
    
    puts( "" );
}

void Queue_enqueue( Queue * q, const char * value ) 
{
    Node * newNode = ( Node * )malloc( sizeof( Node ) );

    if ( q->size == q->capacity ) 
    {
        // Queue is at capacity, dequeue the oldest element
        Node * temp = q->head;
        q->head = q->head->next;
       
        if ( q->head == NULL ) 
        {
            q->tail = NULL;
        }
       
        free( temp->data ); // Free the memory allocated for the string
        free( temp );
        
        q->size--;
    }
    
    // Add the new element
    newNode->data = malloc( strlen( value ) + 1 );
    strcpy( newNode->data, value );
    newNode->next = NULL;
    
    if ( q->tail == NULL ) 
    {
        q->head = q->tail = newNode;
    } 
    else 
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    
    q->size++;
}

char * Queue_getLastElement( Queue * q ) 
{
    char * copy = NULL;

    isNeedToClear = 1;

    if ( q->tail == NULL ) 
    {
        puts( "QUEUE: Empty" );
        return NULL;
    }
    
    // Create a copy of the string
    copy = malloc( strlen( q->tail->data ) + 1 );
    strcpy( copy, q->tail->data );
    
    return copy;
}

void Queue_clear( Queue * q ) 
{
    Node * current = q->head;
    Node * next;

    while ( current != NULL ) 
    {
        next = current->next;
        free( current->data ); // Free the memory allocated for the string
        free(current);
        current = next;
    }

    q->head = q->tail = NULL;
    q->size = 0;
}

void Queue_deleteLastElement( Queue * q )
{
    Node * current = q->head;

    if ( q->tail == NULL )
    {
        puts( "QUEUE: Empty" );
        return;
    }

    if ( q->head == q->tail )
    {
        free( q->tail->data );
        free( q->tail );
        q->head = q->tail = NULL;
        q->size = 0;
        return;
    }
    
    while ( current->next != q->tail )
    {
        current = current->next;
    }

    free( q->tail->data );
    free( q->tail );

    q->tail = current;
    q->tail->next = NULL;
    q->size--;
}

size_t Queue_getSize( Queue * q )
{
    return q->size;
}

char * Queue_getNthElement( Queue * q, size_t n ) 
{
    size_t index = 0;
    Node * current = q->head;
    char * copy = NULL;

    isNeedToClear = 1;

    n--;

    if ( n >= q->size ) 
    {
        puts( "QUEUE: Index out of range" );
        return NULL;
    }
    
    while ( current != NULL && index < n ) 
    {
        current = current->next;
        index++;
    }
    
    copy = malloc( strlen( current->data ) + 1 );
    strcpy( copy, current->data );

    return copy;
}