#include<stdio.h>
#include<math.h>

enum Number {NO_SOLUTION, INFINITE_SOLUTIONS, ONE_SOLUTION, TWO_SOLUTIONS};
Number num;

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

void read (double &a, double &b, double &c)
{
    printf("Hello! You can solve the equation form a*x^2 + b*x +c = 0 with this program.\nSo,\n");

    printf("enter the coefficient a\n");
    read_coefficient(a);
    printf("enter the coefficient b\n");
    read_coefficient(b);
    printf("enter the coefficient c\n");
    read_coefficient(c);
}

void solve (double a, double b, double c, double &x1, double &x2)
{
    double d = 0;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                num = INFINITE_SOLUTIONS;
            else
                num = NO_SOLUTION;
        }
        else
        {
            x1 = -c/b;
            num = ONE_SOLUTION;
        }
    }
    else
    {
        d = b*b - 4*a*c;
        if (d < 0)
            num = NO_SOLUTION;
        else
        {
            if (d > 0)
            {
                x1 = (-b - sqrt(d))/(2*a);
                x2 = (-b + sqrt(d))/(2*a);
                num = TWO_SOLUTIONS;
            }
            else
            {
                x1 = -b/(2*a);
                num = ONE_SOLUTION;
            }
        }
    }
}

void write_solution (double x1, double x2)
{
   switch (num)
    {
        case NO_SOLUTION:
            printf("No solution\n");
            break;
        case INFINITE_SOLUTIONS:
            printf("Infinite solutions\n");
            break;
        case ONE_SOLUTION:
            printf("The solution of equation is \nx = %lg", x1);
            break;
        case TWO_SOLUTIONS:
            printf("The solutions of equation are \nx1 = %lg\nx2 = %lg", x1, x2);
            break;
        default: break;
    }
}
