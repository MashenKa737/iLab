#include "stack.h"

Stack_t *new_stack()
{
    Stack_t *st = (Stack_t *)malloc(sizeof(*st));
    assert(st);
    st->top = NULL;
    return st;
}

int stack_push(Stack_t *st, double a)
{
    Elem_t *element = (Elem_t *)malloc(sizeof(*element));
    if(element&&st)
    {
        element->value = a;
        element->next = st->top;
        st->top = element;
        return 1;
    }
    else
        return 0;
}

int stack_pop(Stack_t *st, double *a)
{
    Elem_t *dnext;
    if (st && st->top)
    {
        *a = st->top->value;
        dnext = st->top->next;
        free(st->top);
        st->top = dnext;
        return 1;
    }
    else
        return 0;

}

void delete_stack(Stack_t *st)
{
    Elem_t *dnext;
    assert(st);
    while(st->top)
    {
        dnext = st->top->next;
        free(st->top);
        st->top = dnext;
    }
    free(st);
}
