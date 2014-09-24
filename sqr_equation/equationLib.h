#ifndef EQUATIONLIB_H
#define EQUATIONLIB_H

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

enum Number {NO_SOLUTION, INFINITE_SOLUTIONS, ONE_SOLUTION, TWO_SOLUTIONS};
void read_coefficient (double &n);
void read (double &a, double &b, double &c);
Number solve (double a, double b, double c, double &x1, double &x2);
void write_solution (double x1, double x2, Number num);

#endif
