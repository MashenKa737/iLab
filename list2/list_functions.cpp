#include "list2.h"

List2_t *ctor_List(int size_el, Errors(*insert_elem)(void*, const void*), Errors(*delete_elem)(void*))
{
    List2_t *nlist  = (List2_t *)malloc(sizeof(List2_t));
    assert(nlist);
    nlist->head = NULL;
    nlist->tail = NULL;
    nlist->list_size = 0;
    nlist->size_elem = size_el;
    nlist->insert_elem = insert_elem;
    nlist->delete_elem = delete_elem;
    return nlist;
}

Errors push_head(List2_t *sp, void *val)
{
    if(sp == NULL)
        return FALSE_LIST;
    Elem_t *nelem = (Elem_t*)malloc(sizeof(Elem_t));
    if(nelem == NULL)
        return ERROR_MEMORY;
    nelem->value = malloc(sp->size_elem);
    if(sp->insert_elem(nelem->value, val) != OK)
        return FALSE;
    if(sp->list_size == 0)
    {
        nelem->last = NULL;
        nelem->next = NULL;
        sp->head = nelem;
        sp->tail = nelem;
    }
    else
    {
        nelem->next = sp->head;
        nelem->last = NULL;
        sp->head->last = nelem;
        sp->head = nelem;
    }
    sp->list_size++;
    return OK;
}

Errors push_tail(List2_t *sp, void *val)
{
    if(sp == NULL)
        return FALSE_LIST;
    Elem_t *nelem = (Elem_t*)malloc(sizeof(Elem_t));
    if(nelem == NULL)
        return ERROR_MEMORY;
    nelem->value = malloc(sp->size_elem);
    if(sp->insert_elem(nelem->value, val) != OK)
        return FALSE;
    if(sp->list_size == 0)
    {
        nelem->last = NULL;
        nelem->next = NULL;
        sp->head = nelem;
        sp->tail = nelem;
    }
    else
    {
        nelem->next = NULL;
        nelem->last = sp->tail;
        sp->tail->next = nelem;
        sp->tail = nelem;
    }
    sp->list_size++;
    return OK;
}

Errors pop_head(List2_t *sp)
{
    if(!sp)
        return FALSE_LIST;
    if(!sp->head)
        return ERR_EMPTY;
    sp->head->next->last = NULL;
    if(sp->delete_elem(sp->head->value) != OK)
        return FALSE;
    free(sp->head->value);
    Elem_t *point = sp->head->next;
    free(sp->head);
    sp->head = point;
    sp->list_size--;
    return OK;
}

Errors pop_tail(List2_t *sp)
{
    if(!sp)
        return FALSE_LIST;
    if(!sp->tail)
        return ERR_EMPTY;
    if(sp->delete_elem(sp->tail->value) != OK)
        return FALSE;
    free(sp->tail->value);
    sp->tail->last->next = NULL;
    Elem_t *point = sp->tail->last;
    free(sp->tail);
    sp->tail = point;
    sp->list_size--;

    return OK;
}

Elem_t *get_point(List2_t *sp, int nom)
{
    int i = 0;
    Elem_t *point;

    if ((sp->list_size - 1 - nom) > nom)
    {
        point = sp->head;
        for(i = 0; i < nom; i++)
            point = point->next;
    }
    else
    {
        point = sp->tail;
        for(i = sp->list_size - 1; i > nom; i--)
            point = point->last;
    }
    return point;
}

Errors insert_after_point(List2_t * sp, Elem_t *point, void *val)
{
    if(!sp)
        return FALSE_LIST;
    Elem_t *nelem = (Elem_t*)malloc(sizeof(Elem_t));
    if(nelem == NULL)
        return ERROR_MEMORY;

    nelem->value = malloc(sp->size_elem);
    if(sp->insert_elem(nelem->value, val) != OK)
        return FALSE;
    nelem->last = point;
    nelem->next = point->next;
    if(nelem->next)
        point->next->last = nelem;
    else
        sp->tail = nelem;
    point->next = nelem;
    sp->list_size++;
    return OK;
}

Errors insert_nom(List2_t *sp, int nom, void* val)
{
    Errors err;
    Elem_t *point;

    if(sp == NULL)
        return FALSE_LIST;
    if (nom > sp->list_size)
        return FALSE;
    if (nom == 0)
    {
        push_head(sp, val);
        return OK;
    }

    else
    {
    point = get_point(sp,nom - 1);
    err = insert_after_point(sp, point, val);
    }
    return err;
}

Errors delete_point(List2_t *sp, Elem_t *point)
{
    if(sp == NULL)
        return FALSE_LIST;
    if(sp->list_size == 0)
        return ERR_EMPTY;
    if(point->last)
        point->last->next = point->next;
    else
        sp->head = sp->head->next;
    if(point->next)
        point->next->last = point->last;
    else
        sp->tail = sp->tail->last;
    if(sp->delete_elem(point->value) != OK)
        return FALSE;
    free(point);
    sp->list_size--;
    return OK;
}

Errors delete_nom(List2_t *sp, int nom)
{
    Elem_t *point;
    Errors err;

    if(sp == NULL)
        return FALSE_LIST;
    if (nom > sp->list_size)
        return FALSE;
    point = get_point(sp, nom);
    err = delete_point(sp, point);
    return err;
}

Errors delete_list(List2_t *sp)
{
    Elem_t *point;
    if(sp == NULL)
        return FALSE_LIST;
    point = sp->head;
    while(sp->head)
    {
        if(sp->delete_elem(sp->head->value) != OK)
            return FALSE;
        point = sp->head->next;
        free(sp->head);
        sp->head = point;
    }
    free(sp);
    return OK;
}

Errors if_in_list(List2_t *sp, Elem_t *point)
{
    Elem_t *p = sp->head;
    int i = 0;
    if(sp == NULL)
        return FALSE_LIST;
    for (i = 0; i < sp->list_size; i++)
    {
        if (p == point)
            return OK;
        p = p->next;
    }
    return FALSE_POINT;
}

void* get_value(List2_t *sp, Elem_t *point)
{
    return point->value;
}
