#ifndef LIST2_H
#define LIST2_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum Errors {OK, ERROR_MEMORY, FALSE_POINT, FALSE_LIST, FALSE, ERR_EMPTY};

typedef struct Elem
{
    void* value;
    struct Elem * next;
    struct Elem * last;
} Elem_t;

typedef struct List2
{
    Elem_t *head;
    Elem_t *tail;
    int list_size;
    int size_elem;//it is size of one element in list
    Errors (*insert_elem) (void*, const void*);
    /*it's a function that user must write;
    It takes arguments void* value_to and const void* value_from
    and copies value of one element from value_from to value_to;
    if there are pointer in element, user must allocate memory for it himself.
    If insert of element is successful, return OK.
    */
    Errors (*delete_elem) (void*);
    /*it's a function that user must write;
    It frees memory of one element that user allocated.
    If delete of element is successful, return OK.
    */
}List2_t;

List2_t *ctor_List(int size_el, Errors(*insert_elem)(void*, const void*), Errors(*delete_elem)(void*));
/*this function creates new list and returns pointer to it;
it takes size of one element in list and two user's function: insert_elem and delete_elem.
*/

Errors push_head(List2_t *sp, void *val);//add element in the begin of list

Errors push_tail(List2_t *sp, void *val);//add element in the end of list

Errors pop_head(List2_t *sp);//delete first element

Errors pop_tail(List2_t *sp);//delete last element

Elem_t *get_point(List2_t *sp, int nom);//return point with number nom

Errors insert_after_point(List2_t * sp, Elem_t *point, void *val);//add element after point

Errors insert_nom(List2_t *sp, int nom, void *val);//add element in list: its number is nom

Errors delete_point(List2_t *sp, Elem_t *point);//delete element with this point

Errors delete_nom(List2_t *sp, int nom);//delete element with number nom

Errors delete_list(List2_t *sp);

Errors if_in_list(List2_t *sp, Elem_t *point);

/*all functions type Errors return OK if they are finish their work successfully
if they takes pointer NULL, return FALSE_LIST;
functions adding element can returns ERROR_MEMORY;
functions deleting element can returns ERR_EMPTY;
functions, uses insert_elem or delete_elem can return FALSE, if the user's function don't return OK.
*/

#endif // LIST2_H
