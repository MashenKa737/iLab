#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Elem
{
    int value;
    struct Elem *next;
} Elem_t;

typedef struct Stack
{
    Elem_t *top;
} Stack_t;

//this function creates new stack and returns pointer to it;
Stack_t *new_stack();

//add element with value "a" to stack,
//if there are no free memory or stack does not exist, return 0,
//else return 1;
int stack_push(Stack_t *st, int a);

//get top element from stack into a,
//if stack is empty or does not exist return 0,
//else return 1;
int stack_pop(Stack_t *st, int *a);

//free the memory of stack;
void delete_stack(Stack_t *st);

#endif // MY_STACK_H
