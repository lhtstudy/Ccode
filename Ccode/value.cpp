#include "stdio.h"
#include "stdlib.h"

void changeVaule(int & x)
{
    x = 1024;
    printf("the value of x is %d\n", x);
}

int   main()
{
    int x = 1;
    printf("the value of x is %d\n", x);
    changeVaule(x);
    printf("the value of x is %d\n", x);
    return EXIT_SUCCESS;
}