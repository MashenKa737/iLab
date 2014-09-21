#include <stdlib.h>
#include <stdio.h>
#include <math.h>
const int NO_SOLUTION = -1;
const int INFINITE_SOLUTIONS = 0;

void read_coefficient (double &a);

int solve (double a, double b, double c, double &x1, double &x2);

void write_solution (int p, double x1, double x2);

int main()
{
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    int k = 0;

    printf("Hello! You can solve the equation form a*x^2 + b*x +c = 0 with this program.\nSo,\n");

    printf("enter the coefficient a\n");
    read_coefficient(a);
    printf("enter the coefficient b\n");
    read_coefficient(b);
    printf("enter the coefficient c\n");
    read_coefficient(c);

    k = solve(a, b, c, x1, x2);
    write_solution(k, x1, x2);

    return 0;
}

void read_coefficient (double &n)
{
    int i = 0;
    i = scanf ("%lg", &n);
    while (i == 0)
    {
        printf("It's a mistake here. Try again, please!\n");
        fflush(stdin);
        i = scanf ("%lg,", &n);
    }
}

int solve (double a, double b, double c, double &x1, double &x2)
{
    double d = 0;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                return INFINITE_SOLUTIONS;
            else
                return NO_SOLUTION;
        }
        else
        {
            x1 = -c/b;
            return 1;
        }
    }
    else
    {
        d = b*b - 4*a*c;
        if (d < 0)
            return NO_SOLUTION;
        else
        {
            if (d > 0)
            {
                x1 = (-b - sqrt(d))/(2*a);
                x2 = (-b + sqrt(d))/(2*a);
                return 2;
            }
            else
            {
                x1 = -b/(2*a);
                return 1;
            }
        }
    }
}

void write_solution (int p, double x1, double x2)
{
   switch (p)
    {
        case NO_SOLUTION:
            printf("No solution\n");
            break;
        case INFINITE_SOLUTIONS:
            printf("Infinite solutions\n");
            break;
        case 1:
            printf("The solution of equation is x = %lg", x1);
            break;
        case 2:
            printf("The solutions of equation are \nx1 = %lg\nx2 = %lg", x1, x2);
            break;
        default: break;
    }
}
