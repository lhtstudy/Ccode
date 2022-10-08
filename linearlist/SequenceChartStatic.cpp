#include <stdio.h>
// 顺序表静态分配
/**
 * @brief 顺序表最大长度，用于初始化数组
 *
 */
#define MAX_SIZE 10
/**
 * @brief 整形链表
 *
 */
typedef struct
{
    int data[MAX_SIZE]; // 数据
    int length;           // 长度
} sqList;

/**
 * @brief 初始化链表
 *
 * @param list 需要初始化的链表
 */
void initList(sqList &list)
{
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        // 全部初始化为0
        list.data[i] = 0;
    }
    list.length = 0;
}

/**
 * @brief 顺序表插入
 *
 * @param list 顺序表
 * @param location 插入元素位序
 * @param element 需要插入的元素
 */
void insertElement(sqList &list, int location, int element)
{
    // 表满禁止插入
    if (list.length == MAX_SIZE)
    {
        printf("顺序表已满!\n");
        return;
    }
    // 输入数据不合法处理
    if (location < 1 || location > list.length + 1)
    {
        printf("输入数据不合法!\n");
        return;
    }
    // 插入之后的元素顺序后移一位
    for (size_t i = list.length; i >= location; i--)
    {
        list.data[i] = list.data[i - 1];
    }
    list.data[location - 1] = element;
    list.length++;
}

/**
 * @brief 顺序表删除
 *
 * @param list 顺序表
 * @param location 删除元素的位序
 * @param e 被删除的元素
 */
void deleteElement(sqList &list, int location, int &e)
{
    // 输入数据不合法
    if (location < 1 || location > list.length)
    {
        printf("输入数据不合法!\n");
        return;
    }
    e = list.data[location - 1];
    // 删除位置之后的元素顺序前移
    for (size_t i = location; i <= list.length; i++)
    {
        list.data[i - 1] = list.data[i];
    }
    list.length--;
}

/**
 * @brief Get the Location By Value object
 *
 * @param list 顺序表
 * @param e 元素值
 * @return int 该元素在顺序表中的位序，-1表示顺序表中不存在为该元素值的元素
 */
int getLocationByValue(sqList &list, int e)
{
    for (size_t i = 0; i < list.length; i++)
    {
        if (list.data[i] == e)
        {
            return i + 1;
        }
    }
    return -1;
}

/**
 * @brief Get the Value By Location object
 *
 * @param list 顺序表
 * @param i 位序
 * @return int 该位序上是元素值
 */
int getValueByLocation(sqList &list, int i)
{
    // 输入数据不合法
    if (i < 1 || i > list.length)
    {
        printf("输入数据不合法!\n");
        return -1;
    }
    return list.data[i - 1];
}

/**
 * @brief Get the Length object
 *
 * @param list 顺序表
 * @return int 长度
 */
int getLength(sqList &list)
{
    return list.length;
}

/**
 * @brief 打印顺序表
 *
 * @param list 顺序表
 */
void toString(sqList &list)
{
    printf("{");
    for (size_t i = 0; i < list.length; i++)
    {
        printf("%d", list.data[i]);
    }
    printf("}\n");
}

/**
 * @brief 判断顺序表是否是空表
 *
 * @param list 顺序表
 */
void isEmpty(sqList &list)
{
    if (list.length == 0)
    {
        printf("顺序表为空\n");
        return;
    }
    printf("顺序表长度为%d\n", list.length);
}

int main()
{
    sqList list;
    initList(list);
    isEmpty(list);
    insertElement(list, 1, 5);
    insertElement(list, 2, 4);
    insertElement(list, 2, 2);
    isEmpty(list);
    toString(list);
    // deleteElement(list, 1, temp);
    // toString(list);
    getLocationByValue(list, 6);
    printf("%d\n", getValueByLocation(list, 1));
    printf("%d\n", getValueByLocation(list, 5));
    printf("%d\n", getValueByLocation(list, -4));
    return 0;
}
