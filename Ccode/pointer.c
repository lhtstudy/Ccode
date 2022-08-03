#include "stdio.h"

void change(int *p, int c)
{
    *p = c;
}

void main()
{
    int a = 10;
    printf("%d", a);
    putchar('\n');
    change(&a, 5);
    printf("%d", a);
}