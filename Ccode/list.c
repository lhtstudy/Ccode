#include "stdio.h"
#include "stdlib.h"

/**
 * @brief int list
 *
 */
typedef struct list
{
    int score;
    struct list *next;
} Linklist;

/**
 * @brief create list
 *
 * @param n the number of nodes
 * @return Linklist*
 */
Linklist *create(int n)
{
    Linklist *head, *node, *end;
    head = (Linklist *)malloc(sizeof(Linklist));
    end = head;
    for (size_t i = 0; i < n; i++)
    {
        node = (Linklist *)malloc(sizeof(Linklist));
        // printf("input %s node's score", i);
        // scanf("%d", &node->score);
        node->score = i;
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}

/**
 * @brief modify node's score
 *
 * @param list the list to modify
 * @param n The location of the node to modify
 */
void change(Linklist *list, int n)
{
    Linklist *t = list;
    int i = 0;
    while (i < n && t != NULL)
    {
        t = t->next;
        i++;
    }
    if (t != NULL)
    {
        // puts("请输入要修改的节点值");
        // scanf("%d", &t->score);
        t->score = 9;
    }
    else
    {
        puts("节点不存在请重新输入");
    }
}

Linklist *delete (Linklist *list, int n)
{
    Linklist *t = list;
    Linklist *in;
    int i = 0;
    while (i < n && t != NULL)
    {
        in = t;
        t = t->next;
        i++;
    }
    if (t != NULL)
    {
        in->next = t->next;
        free(t);
    }
    return in;
}

// void insert(Linklist *list, int n)
// {
// }

void listToString(Linklist *list)
{
    Linklist *t = list;
    while (t->next != NULL)
    {
        t = t->next;
        printf("%d", t->score);
    }
}

void main()
{
    Linklist *list = create(5);
    change(list, 2);
    delete(list, 2);
    listToString(list);
}
