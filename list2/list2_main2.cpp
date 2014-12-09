#include "list2.h"
#include <string.h>

Errors insert_str(void *str_to, const void *str_from);
Errors insert_list(void *list_to, const void *list_from);
Errors delete_str(void* mstr);
Errors delete_list(void* mlist);
void print_list(List2_t *list_str);
List2_t* if_letter(List2* sp, char* str);
Errors insert_str_list(List2_t* list_list, char* s);

int main()
{
    char s[100];
    List2_t *list_list = NULL;
    int i = 0, n = 0;
    Elem_t* p = NULL;
    FILE* fin = fopen("list_for.dat", "r");

    list_list = ctor_List(sizeof(List2_t**), insert_list, delete_list);
    fscanf(fin, "%d", &n);
    for(i = 0; i < n; i++)
    {
        fscanf(fin, "%s", s);
        insert_str_list(list_list, s);
    }

    p = list_list->head;
    for(i = 0; i < list_list->list_size; i++)
    {
        print_list(*(List2_t**)p->value);
        p = p->next;
    }

    fclose(fin);
    return 0;
}

Errors insert_str_list(List2_t* list_list, char* s)
{
    List2_t *li2 = NULL;

    li2 = if_letter(list_list, s);
    if(li2)
    {
        if(push_tail(li2, s) != OK)
            return ERROR_MEMORY;
    }

    else
    {
        if(push_tail(list_list, s) != OK)
            return ERROR_MEMORY;
    }
    return OK;
}

Errors insert_str(void *str_to, const void *str_from)
{
    int i = 0, n = 0;
    n = strlen((char*)str_from) + 1;
    *(char**)str_to = (char*)calloc(n, sizeof(char));
    if(*(char**)str_to == NULL)
        return ERROR_MEMORY;
    for(i = 0; i < n; i++)
    {
        *((*(char**)str_to)+ i) = *(((char*)str_from)+i);
    }
    return OK;
}

List2* if_letter(List2_t* sp, char* str)
{
    Elem_t*p = sp->head;
    int i = 0;
    for(i = 0; i < sp->list_size; i++)
    {
        if(*(*(char**)(*(List2_t**)p->value)->head->value) == *str)
        return *(List2_t**)p->value;
        p = p->next;
    }
    return 0;
}

Errors insert_list(void *list_to, const void *str_from)
{
    char *s = (char*)str_from;
    *(List2_t**)list_to = ctor_List(sizeof(char**), insert_str, delete_str);
    if(*(List2_t**)list_to == NULL)
        return ERROR_MEMORY;
    push_tail(*(List2_t**)list_to, s);
    return OK;
}

Errors delete_str(void* mstr)
{
    return OK;
}

Errors delete_list(void* mlist)
{
    return OK;
}

void print_list(List2_t *list_str)
{
    Elem_t *p;
    int i = 0;

    printf("*****\n");
    p = list_str->head;
    for(i = 0; i < list_str->list_size; i++)
    {
        printf("%s\n", *(char**)get_value(list_str, p));
        p = p->next;
    }
    printf("*****\n");
}
