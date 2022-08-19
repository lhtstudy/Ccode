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

/**
 * @brief delete specified node
 *
 * @param list the list to modify
 * @param n The location of the node to delete
 * @return Linklist* modified list
 */
Linklist *delete(Linklist *list, int n)
{
    Linklist *t = list;
    Linklist *ret;
    int i = 0;
    while (i < n && t != NULL)
    {
        ret = t;
        t = t->next;
        i++;
    }
    if (t != NULL)
    {
        ret->next = t->next;
        free(t);
    }
    return ret;
}

/**
 * @brief insert new node to list
 *
 * @param list the list to modify
 * @param n The location of the node to insert
 * @return Linklist* modified list
 */
Linklist *insert(Linklist *list, int n)
{
    Linklist *t = list;
    int i = 0;
    Linklist *ret;
    while (i < n && t != NULL)
    {
        ret = t;
        t = t->next;
        i++;
    }
    Linklist *newNode = (Linklist *)malloc(sizeof(Linklist));
    newNode->score = 8;
    ret->next = newNode;
    newNode->next = t;
    return ret;
}

/**
 * @brief output list
 *
 * @param list
 */
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
    delete (list, 2);
    insert(list, 2);
    listToString(list);
}
