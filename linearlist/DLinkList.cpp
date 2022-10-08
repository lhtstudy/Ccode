#include <iostream>
using namespace std;

/**
 * @brief 整形双链表
 *
 */
typedef struct DouLinkList
{
    int data;
    struct DouLinkList *pre;
    struct DouLinkList *next;
} DLNode, *DLinkList;

/**
 * @brief 初始化双链表
 *
 * @param doubleLinkList 双链表
 * @return true 初始化成功
 * @return false 失败
 */
bool initList(DLinkList &doubleLinkList)
{
    // 申请头结点
    DLNode *head = new DLNode;
    doubleLinkList = head;
    // 申请内存失败
    if (head == NULL)
    {
        return false;
    }
    // 初始化
    head->pre = NULL;
    head->next = NULL;
    head->data = 0;
    return true;
}

/**
 * @brief 向指定位序处插入指定值的节点
 *
 * @param doubleLinkList 双链表
 * @param location 位序
 * @param data 数据
 * @return true 插入成功
 * @return false 失败
 */
bool insertNode(DLinkList &doubleLinkList, int location, int data)
{
    // 位序小于1数据不合法
    if (location < 1)
    {
        return false;
    }
    DLNode *tmpNode = doubleLinkList; // 临时节点遍历链表
    int number = 1;                   // 记录当前位置
    do
    {
        // 当前位置为插入节点的前一个节点
        if (number == location)
        {
            // 申请新节点
            DLNode *newNode = new DLNode;
            // 改变指针
            newNode->next = tmpNode->next;
            // 如果有后继节点
            if (tmpNode->next != NULL)
            {
                tmpNode->next->pre = newNode;
            }
            newNode->pre = tmpNode;
            tmpNode->next = newNode;
            // 赋值
            newNode->data = data;
            return true;
        }
        number++;
        tmpNode = tmpNode->next;
    } while (tmpNode != NULL);
    return false;
}

/**
 * @brief 删除指定位序的节点
 * 
 * @param doubleLinkList 双链表
 * @param location 位序
 * @return true 删除成功
 * @return false 失败
 */
bool removeNodeByLoction(DLinkList &doubleLinkList, int location)
{
    if (location < 1)
    {
        return false;
    }
    DLNode *tmpNode = doubleLinkList; // 临时节点遍历链表
    int number = 0;                   // 记录当前位置
    do
    {
        // 当前位置为删除节点
        if (number == location)
        {
            // 改变指针
            tmpNode->pre->next = tmpNode->next;
            // 如果有后继节点
            if (tmpNode->next != NULL)
            {
                tmpNode->next->pre = tmpNode->pre;
            }
            delete (tmpNode);
            return true;
        }
        number++;
        tmpNode = tmpNode->next;
    } while (tmpNode != NULL);
    return false;
}

/**
 * @brief 删除指定值的节点
 * 
 * @param doubleLinkList 双链表
 * @param data 数据
 * @return true 删除成功
 * @return false 失败
 */
bool removeNodeBydata(DLinkList &doubleLinkList, int data)
{
    DLNode *tmpNode = doubleLinkList->next; // 临时节点遍历链表，从第一个节点开始
    while (tmpNode != NULL)
    {
        // 当前位置为删除节点
        if (tmpNode->data == data)
        {
            // 改变指针
            tmpNode->pre->next = tmpNode->next;
            // 如果有后继节点
            if (tmpNode->next != NULL)
            {
                tmpNode->next->pre = tmpNode->pre;
            }
            delete (tmpNode);
            return true;
        }
        tmpNode = tmpNode->next;
    }
    return false;
}

/**
 * @brief 打印双链表
 *
 * @param doubleLinkList 双链表
 */
void toString(DLinkList &doubleLinkList)
{
    cout << '{';
    while (doubleLinkList->next != NULL)
    {
        doubleLinkList = doubleLinkList->next;
        cout << doubleLinkList->data;
    }
    cout << '}';
}

int main()
{
    DLinkList dLinkList;
    initList(dLinkList);
    insertNode(dLinkList, 1, 5);
    insertNode(dLinkList, 1, 4);
    insertNode(dLinkList, 1, 3);
    insertNode(dLinkList, 1, 2);
    insertNode(dLinkList, 1, 1);
    insertNode(dLinkList, 2, 9);
    removeNodeByLoction(dLinkList, 2);
    cout << removeNodeByLoction(dLinkList, 10) << endl;
    removeNodeByLoction(dLinkList, 5);
    removeNodeBydata(dLinkList, 3);
    cout << removeNodeBydata(dLinkList, 5) << endl;
    toString(dLinkList);
    return 0;
}