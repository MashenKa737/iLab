#include <stdio.h>
#include <math.h>
int main (){
    double a, b, c;
    double d, x1, x2;
    printf("Enter the coefficients a, b and c of equation:\nax2+bx+c=0\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a==0){
        if (b==0) {
            if (c==0)
                printf("infinite number of solutions");
            else
                printf("no solution"); }
        else {
            x1 = -c/b;
            printf("x = %lf",x1); } }
    else {
        d = b*b-4*a*c;
        if (d<0)
            printf("no solution");
        else {
            x1 = (-b+sqrt(d))/2;
            if (d==0)
                printf("x = %lf", x1);
            else {
              x2 = (-b-sqrt(d))/2;
              printf("x1 = %lf, x2 = %lf", x1, x2); } } }
    return 0;
}
