#include "stdio.h"
#include "stdlib.h"

void changeVaule(int *x)
{
    *x = 1024;
    printf("the value of x is %d\n", *x);
}

void main()
{
    int x = 1;
    printf("the value of x is %d\n", x);
    changeVaule(&x);
    printf("the value of x is %d\n", x);
}