#include "list2.h"

typedef struct Mass
{
    int *arr;
    int size_arr;
}Mass_t;

Errors insert_mass (void* val, const void *val_fr);
Errors delete_mass (void* val);
void print_list (List2_t *sp);

int main()
{
    int i;
    Elem_t *el;
    List2_t *sp = ctor_List(sizeof(Mass_t*), insert_mass, delete_mass);
    Mass_t *m = (Mass_t*)malloc(sizeof(Mass_t));
    m->arr = (int*)calloc(5, sizeof(int));
    m->size_arr = 5;
    for(i = 0; i < 5; i++)
        m->arr[i] = i;
    push_tail(sp, m);

    for(i = 0; i < 3; i++)
        {
            m->arr[i] = 13;
            push_tail(sp, m);
        }
    free(m->arr);
    m->arr = (int*)calloc(1, sizeof(int));
    m->size_arr = 1;
    m->arr[0] = 2;

    for(i = 0; i < 3; i++)
        push_head(sp, m);

    print_list(sp);
    pop_tail(sp);
    pop_head(sp);
    print_list(sp);

    el = sp->head;
    if(if_in_list(sp, el) == OK)
        printf("point is OK\n");
    m->arr[0] = -247;

    if (insert_nom(sp,2, m) == OK)
    {
        el = get_point(sp, 2);
        printf("OK 2 el:\n");
        for(i = 0; i < ((Mass_t*)el->value)->size_arr; i++)
            printf("%d ", ((Mass_t*)el->value)->arr[i]);
        printf("\n");
    }

    if (delete_nom(sp,2) == OK)
    {
        el = get_point(sp, 2);
        printf("OK 2 el:\n");
        for(i = 0; i < ((Mass_t*)el->value)->size_arr; i++)
            printf("%d ", ((Mass_t*)el->value)->arr[i]);
        printf("\n");
    }

    m->arr[0] = -777;
    for(i = 0; i < 100000; i++)
    {
        if(push_tail(sp, m) == ERROR_MEMORY)
        {
            printf("\nNO FREE MEMORY");
            break;
        }
    }

    printf("\n%d", ((Mass_t*)sp->tail->value)->arr[0]);
    delete_list(sp);
    return 0;
}

void print_list (List2_t *sp)
{
    Elem_t *el;
    int i;
    el = sp->head;
    printf("list size = %d\n", sp->list_size);
    for(i = 0; i < sp->list_size; i++)
    {
        int j = 0;
        int a = ((Mass_t*)el->value)->size_arr;
        for(j = 0; j < a; j++)
            printf("%d ", ((Mass_t*)el->value)->arr[j]);
        printf("\n");
        printf("*****\n");
        el = el->next;
    }
    printf("\n");
}

Errors insert_mass (void* val, const void *val_fr)
{
    int i, s;
    s = ((Mass_t*)val_fr)->size_arr;
    ((Mass_t*)val)->size_arr = s;
    ((Mass_t*)val)->arr = (int*)malloc(sizeof(int)*s);
    if(((Mass_t*)val)->arr == NULL)
        return ERROR_MEMORY;
    for(i = 0; i < s; i++)
    {
        ((Mass_t*)val)->arr[i] = ((Mass_t*)val_fr)->arr[i];
    }
    return OK;
}

Errors delete_mass (void* val)
{
    free(((Mass_t*)val)->arr);
    return OK;
}
