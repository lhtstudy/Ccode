#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *list = (int *)malloc(sizeof(int) * 15);
    // int *list = (int *)calloc(15, sizeof(int));
    for (size_t i = 0; i < 10; i++)
    {
        list[i] = i;
    }
    for (size_t i = 0; i < 15; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    printf("%x\n", list);
    list = (int *)realloc(list, sizeof(int) * 4);
    printf("%x\n", list);
    for (size_t i = 0; i < 15; i++)
    {
        printf("%d ", list[i]);
    }
    return 0;
}
