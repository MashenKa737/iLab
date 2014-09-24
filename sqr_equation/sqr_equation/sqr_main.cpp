#include "equationLib.h"

int main()
{
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    Number num;

    read(a,b,c);
    num = solve(a, b, c, x1, x2);
    write_solution(x1, x2, num);

    return 0;
}

