#include "list2.h"

int main()
{
    int a;
    int i;
    List2_t *sp;
    Elem_t *el;

    sp = ctor_List();
    for(i = 0; i < 5; i++)
        push_tail(sp, i);
    for(i = 0; i < 2; i++)
        push_head(sp, 13);

    pop_tail(sp, &a);
    printf("last = %d\n", a);

    pop_head(sp, &a);
    printf("first = %d\n", a);

    if (insert_nom(sp,2, -247) == OK)
    {
        el = get_point(sp, 2);
        printf("OK 2 el = %d\n", el->value);
    }

    if (delete_nom(sp,2) == OK)
    {
        el = get_point(sp, 2);
        printf("OK 2 el = %d\n", el->value);
    }
    for(i = 0; i < sp->list_size; i++)
    {
        el = get_point(sp, i);
        printf("%d ", el->value);
    }

    for(i = 0; i < 10000; i++)
    {
        if(push_tail(sp, -777) == ERROR_MEMORY)
        {
            printf("NO FREE MEMORY");
            break;
        }
    }
    printf("\n%d", sp->tail->value);
    delete_list(sp);
    return 0;
}
