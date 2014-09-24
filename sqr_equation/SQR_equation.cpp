#include "equationLib.h"
#include <stdlib.h>
#include <stdio.h>

void read (double &a, double &b, double &c);

void solve (double a, double b, double c, double &x1, double &x2);

void write_solution (int p, double x1, double x2);

int main()
{
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    read(a,b,c);
    solve(a, b, c, x1, x2);
    write_solution(x1, x2);

    return 0;
}
