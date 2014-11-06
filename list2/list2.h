#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

enum Errors {OK, ERROR_MEMORY, FALSE_POINT, NOM_FALSE, ERR_EMPTY};

typedef struct Elem
{
    int value;
    struct Elem * next;
    struct Elem * last;
} Elem_t;

typedef struct List2
{
    Elem_t *head;
    Elem_t *tail;
    int list_size;
}List2_t;

//this function creates new list and returns pointer to it;
List2_t *ctor_List();

//add element in the begin of list
Errors push_head(List2_t *sp, int val);

//add element in the end of list
Errors push_tail(List2_t *sp, int val);

//get first element from list into a
Errors pop_head(List2_t *sp, int *a);

//get last element from list into a
Errors pop_tail(List2_t *sp, int *a);

//return point with number nom
Elem_t *get_point(List2_t *sp, int nom);

//add element after point
Errors insert_after_point(List2_t * sp, Elem_t *point, int val);

//add element in list: its number is nom
Errors insert_nom(List2_t *sp, int nom, int val);

//delete element with this point
Errors delete_point(List2_t *sp, Elem_t *point);

//delete element with number nom
Errors delete_nom(List2_t *sp, int nom);

//this function deletes list;
Errors delete_list(List2_t *sp);
