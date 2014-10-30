#include "stack.h"
int main()
{
    int a = 0, b = 0, k = 0, n = 0;
    long int i = 0;
    Stack_t *mstack;

    mstack = new_stack();

    printf("Now enter the number N and enter N integer elements to push\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b);
        stack_push(mstack, b);
    }

    printf("Enter the number M of elements to pop\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        k = stack_pop(mstack, &a);
        if (k == 0)
        {
            printf("ERROR POP\nStack is empty\n");
            break;
        }
    }
    if (k)
        printf("last value is %d\n", a);

    printf("Now enter the value of element to push 26843545 times\n");
    scanf("%d", &b);
    for (i = 0; i < 26843545; i++)
    {
        k = stack_push(mstack, b);
        if (k == 0)
        {
            printf("ERROR PUSH");
            break;
        }

    }
    k = stack_pop(mstack, &a);
    if (k)
        printf("last value is %d\n", a);

    delete_stack(mstack);

    return 0;
}

