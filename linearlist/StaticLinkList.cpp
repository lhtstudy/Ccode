#include <iostream>
using namespace std;

#define MAX_SIZE 10 //静态链表最大容量
/**
 * @brief 整形静态链表
 *
 */
typedef struct
{
    int data; // 数据
    int next; // 指向下一个元素在数组中位置的游标
} StaticList, StaticListDefault[MAX_SIZE];

/**
 * @brief 初始化静态链表
 *
 * @param staticListDefault 静态链表
 * @return true 初始化成功
 * @return false 失败
 */
bool initStaticList(StaticListDefault &staticListDefault)
{
    // 头节点初始化
    staticListDefault[0].data = 0;
    // -1表示静态链表末尾
    staticListDefault[0].next = -1;
    // 未存储元素的数组元素游标指向-2
    for (size_t i = 1; i < MAX_SIZE; i++)
    {
        staticListDefault[i].next = -2;
    }
    return true;
}

/**
 * @brief 向静态链表中插入新节点
 *
 * @param staticListDefault 静态链表
 * @param i 插入节点在链表中的位序
 * @param e 插入的元素数据
 * @return true 插入成功
 * @return false 失败
 */
bool insertNode(StaticListDefault &staticListDefault, int i, int e)
{
    // 位序数据非法
    if (i < 0)
    {
        return false;
    }

    int j = 1; // 遍历数组找到空余位置
    while (staticListDefault[j].next != -2)
    {
        j++;
        // 防止下标越界
        if (j == MAX_SIZE)
        {
            return false;
        }
    }
    // 将插入的数据存放在第一个找到的空余位置
    staticListDefault[j].data = e;

    // 从头结点开始找到插入位置之前的节点
    StaticList &frontNode = staticListDefault[0];
    int tmp = 1;
    while (frontNode.next != -1)
    {
        // 判断位置，中间插入
        if (tmp == i)
        {
            staticListDefault[j].next = frontNode.next;
            frontNode.next = j;
            return true;
        }
        tmp++;
        frontNode = staticListDefault[frontNode.next];
    }
    // 当next等于-1时到达链表末尾，可以在末尾插入
    if (tmp == i)
    {
        staticListDefault[j].next = frontNode.next;
        frontNode.next = j;
        return true;
    }
    return false;
}

/**
 * @brief 从静态链表中删除节点
 *
 * @param staticListDefault 静态链表
 * @param i 删除节点在链表中的位序
 * @return true 删除成功
 * @return false 失败
 */
bool removeNode(StaticListDefault &staticListDefault, int i)
{
    // 位序数据非法
    if (i < 0)
    {
        return false;
    }

    // 从头结点开始找到之前的节点
    StaticList &frontNode = staticListDefault[0];
    int tmp = 1;
    while (frontNode.next != -1)
    {
        // 判断位置
        if (tmp == i)
        {
            StaticList &theNode = staticListDefault[frontNode.next];
            frontNode.next = theNode.next;
            return true;
        }
        tmp++;
        frontNode = staticListDefault[frontNode.next];
    }
    return false;
}

/**
 * @brief 打印静态链表
 *
 * @param staticListDefault 静态链表
 */
void toString(StaticListDefault &staticListDefault)
{
    cout << '{';
    StaticList &frontNode = staticListDefault[0];
    // next为-1即为静态链表末尾
    while (frontNode.next != -1)
    {
        frontNode = staticListDefault[frontNode.next];
        cout << frontNode.data;
    }
    cout << '}';
}

/**
 * @brief 打印静态链表存储数组
 *
 * @param staticListDefault 静态链表
 */
void toStringArray(StaticListDefault &staticListDefault)
{
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        cout << staticListDefault[i].data << '\t' << staticListDefault[i].next << endl;
    }
}

int main()
{
    StaticListDefault staticListDefault;
    initStaticList(staticListDefault);
    insertNode(staticListDefault, 1, 5);
    insertNode(staticListDefault, 1, 4);
    insertNode(staticListDefault, 1, 3);
    removeNode(staticListDefault, 1);
    removeNode(staticListDefault, 1);
    toString(staticListDefault);
    // toStringArray(staticListDefault);
    return 0;
}
