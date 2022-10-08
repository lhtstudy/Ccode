#include <stdio.h>
#include <stdlib.h>
// 单链表

/**
 * @brief 整形单链表
 *
 */
typedef struct List
{
    int data;          // 数据域
    struct List *next; // 指针域
} LNode, *LinkedList;

/**
 * @brief 初始化单链表
 *
 * @param linkedList 单链表
 * @return true 初始化成功
 * @return false 初始化失败
 */
bool initLinkedList(LinkedList &linkedList)
{
    // 申请空间作为头结点
    linkedList = (LNode *)malloc(sizeof(LNode));
    if (linkedList == NULL)
    {
        return false;
    }
    // 初始化数据
    linkedList->data = 0;
    linkedList->next = NULL;
    return true;
}

/**
 * @brief 向单链表中插入元素
 *
 * @param linkedList 单链表
 * @param location 位序
 * @param data 元素的值
 * @return true 插入成功
 * @return false 插入失败
 */
bool addNode(LinkedList &linkedList, int location, int data)
{
    if (location < 1)
    {
        return false;
    }
    // 首元节点的位序为1
    int tmp = 1;
    // 临时节点用来遍历链表
    LinkedList frontNode = linkedList;
    // 找到指定位置之前的节点
    while (frontNode != NULL)
    {
        if (tmp == location)
        {
            // 申请新节点赋值
            LNode *newNode = (LNode *)malloc(sizeof(LNode));
            newNode->data = data;
            // 改变指针
            newNode->next = frontNode->next;
            frontNode->next = newNode;
            return true;
        }
        tmp++;
        frontNode = frontNode->next;
    }
    return false;
}

/**
 * @brief 移除指定位序的节点
 *
 * @param linkedList 单链表
 * @param location 位序
 * @return true 删除成功
 * @return false 删除失败
 */
bool removeNodeByLocation(LinkedList &linkedList, int location)
{
    if (location < 1)
    {
        return false;
    }
    // 首元节点的位序为1
    int tmp = 1;
    // 临时节点用来遍历链表
    LinkedList frontNode = linkedList;
    // 找到指定位置之前的节点
    while (frontNode != NULL)
    {
        if (tmp == location)
        {
            // 改变指针
            LNode *theNode = frontNode->next;
            frontNode->next = theNode->next;
            // 释放被删除的节点
            free(theNode);
            return true;
        }
        tmp++;
        frontNode = frontNode->next;
    }
    return false;
}

/**
 * @brief 删除指定值的节点
 *
 * @param linkedList 单链表
 * @param data 值
 * @return true 删除成功
 * @return false 删除失败
 */
bool removeNodeBydata(LinkedList &linkedList, int data)
{
    // 临时节点用来遍历链表
    LinkedList frontNode = linkedList;
    // 找到指定位置之前的节点
    while (frontNode->next != NULL)
    {
        // 改变指针
        LNode *theNode = frontNode->next;
        if (theNode->data == data)
        {
            frontNode->next = theNode->next;
            // 释放被删除的节点
            free(theNode);
            return true;
        }
        frontNode = frontNode->next;
    }
    return false;
}

/**
 * @brief 链表逆置（头插法）
 *
 * @param linkedList 单链表
 * @return true 逆置成功
 * @return false 逆置失败
 */
bool reverseListByInsert(LinkedList &linkedList)
{
    LNode *firstNode = linkedList->next;
    // 链表为空时无需逆置
    if (firstNode == NULL)
    {
        return false;
    }
    // 临时节点用来遍历链表
    LinkedList theNode = firstNode->next;
    while (theNode)
    {
        // 将第二个节点之后的节点按头插法插入到链表中
        addNode(linkedList, 1, theNode->data);
        theNode = theNode->next;
    }
    // 原来的第一个节点变为末尾节点，next指针置空
    firstNode->next = NULL;
    return true;
}

/**
 * @brief 链表逆置（原地逆置法）
 *
 * @param linkedList 单链表
 * @return true 逆置成功
 * @return false 逆置失败
 */
bool reverseList(LinkedList &linkedList)
{
    LNode *firstNode = linkedList->next;
    // 链表为空时无需逆置
    if (firstNode == NULL)
    {
        return false;
    }
    // 从第二个节点开始
    LNode *pre = NULL;
    LNode *cur = firstNode;
    while (cur)
    {
        LNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    // 头节点指向原来的末尾节点
    linkedList->next = pre;
    return true;
}

/**
 * @brief 打印单链表
 *
 * @param linkedList 单链表
 */
void toString(LinkedList &linkedList)
{
    printf("{");
    while (linkedList->next != NULL)
    {
        linkedList = linkedList->next;
        printf("%d ", linkedList->data);
    }
    printf("}");
}

int main()
{
    LinkedList linkedList;
    initLinkedList(linkedList);
    addNode(linkedList, 1, 5);
    addNode(linkedList, 1, 4);
    addNode(linkedList, 1, 3);
    // addNode(linkedList, 1, 2);
    reverseListByInsert(linkedList);
    reverseList(linkedList);
    // removeNodeByLocation(linkedList, 1);
    // removeNodeByLocation(linkedList, 1);
    // removeNodeBydata(linkedList, 5);
    // removeNodeBydata(linkedList, 4);
    // removeNodeBydata(linkedList, 6);
    toString(linkedList);
    return 0;
}