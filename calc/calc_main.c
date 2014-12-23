#include "stack.h"

int main()
{
    FILE* fin = NULL;
    int c = 0;
    double num, ch, rez;
    Stack_t *st;
    st = new_stack();

    fin = fopen("calc.dat", "r");
    if(errno)
    {
        perror("file");
        exit(1);
    }

    while((c = fgetc(fin)) != EOF)
    {
        if(((c >= '0')&&(c <= '9'))||(c == '-'))
        {
            ungetc(c, fin);
            if(fscanf(fin, "%lg", &ch))
                stack_push(st, ch);
            else
            {
                stack_pop(st, &num);
                stack_pop(st, &rez);
                rez -= num;
                stack_push(st, rez);
            }
        }

        else
        {
            switch(c)
            {
            case '+':
                stack_pop(st, &num);
                stack_pop(st, &rez);
                rez += num;
                stack_push(st, rez);
                break;
            case '-':
                stack_pop(st, &num);
                stack_pop(st, &rez);
                rez -= num;
                stack_push(st, rez);
                break;
            case '*':
                stack_pop(st, &num);
                stack_pop(st, &rez);
                rez *= num;
                stack_push(st, rez);
                break;
            case '/':
                stack_pop(st, &num);
                stack_pop(st, &rez);
                rez /= num;
                stack_push(st, rez);
                break;
            default:
                break;
            }
        }

    }

    stack_pop(st, &num);
    printf("%lg", num);
    fclose(fin);
    delete_stack(st);
    return 0;
}

