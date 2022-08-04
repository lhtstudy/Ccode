#include "stdio.h"
#include "stdlib.h"

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
        scanf("%d", &node->score);
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
    Linklist *list = list;
    int i = 0;
    while (i < n && list != NULL)
    {
        list = list->next;
        i++;
    }
    if (list != NULL)
    {
        puts("请输入要修改的节点值");
        scanf("%d", &list->score);
    }
    else
    {
        puts("节点不存在请重新输入");
    }
}

void delete(Linklist *list, int n){

}

void insert(Linklist *list, int n){
    
}

void main()
{
}
