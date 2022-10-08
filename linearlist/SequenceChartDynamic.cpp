#include <stdio.h>
#include <stdlib.h>
// 顺序表动态分配
/**
 * @brief 整形链表
 *
 */
typedef struct
{
    int *data;
    int length;
    int MAX_SIZE;
} sqList;

/**
 * @brief 初始化顺序表
 *
 * @param list 顺序表
 * @param size 最大容量
 */
void initList(sqList &list, int size)
{
    if (size < 0)
    {
        printf("数据不合法！\n");
    }

    // 申请空间
    list.data = (int *)malloc(sizeof(int) * size);
    // 初始化为0
    for (size_t i = 0; i < size; i++)
    {
        list.data[i] = 0;
    }
    list.MAX_SIZE = size;
    list.length = 0;
}

/**
 * @brief 销毁顺序表
 *
 * @param list 顺序表
 */
void destroyList(sqList &list)
{
    free(list.data);
    list.MAX_SIZE = 0;
    list.length = 0;
}

/**
 * @brief 增加顺序表容量
 *
 * @param list 顺序表
 * @param size 容量
 */
void increaseSize(sqList &list, int size)
{
    if (size < list.MAX_SIZE)
    {
        printf("数据不合法！\n");
        return;
    }
    // 临时变量存储原始地址
    // int *tmp = list.data;
    // 申请空间
    // list.data = (int *)malloc(sizeof(int) * size);
    list.data = (int *)realloc(list.data, sizeof(int) * size);
    list.MAX_SIZE = size;
    // // 数据为空则无需复制元素及释放空间
    // if (tmp == NULL)
    // {
    //     return;
    // }
    // // 复制原来的数据到新的空间内
    // for (size_t i = 0; i < size; i++)
    // {
    //     list.data[i] = tmp[i];
    // }
    // // 释放原来申请的空间
    // free(tmp);
}

/**
 * @brief 向顺序表中插入元素
 *
 * @param list 顺序表
 * @param location 位序
 * @param element 元素
 */
void insertElement(sqList &list, int location, int element)
{
    // 表满禁止插入
    if (list.length == list.MAX_SIZE)
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
 * @brief 删除顺序表中的元素
 *
 * @param list 顺序表
 * @param location 位序
 * @param e 返回删除的元素
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
 * @return int 元素的位序
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
 * @param i 元素的位序
 * @return int 元素值
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
 * @return int 表长
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
 * @brief 判断顺序表是否为空
 *
 * @param list 顺序表
 * @return true 为空
 * @return false 不为空
 */
bool isEmpty(sqList &list)
{
    if (list.length == 0)
    {
        printf("顺序表为空\n");
        return true;
    }
    printf("顺序表长度为%d\n", list.length);
    return false;
}

int main()
{
    sqList list;
    initList(list, 5);
    insertElement(list, 1, 5);
    toString(list);
    increaseSize(list, 4);
    // isEmpty(list);
    insertElement(list, 1, 5);
    // isEmpty(list);
    insertElement(list, 2, 4);
    insertElement(list, 2, 2);
    insertElement(list, 2, 2);
    insertElement(list, 2, 2);
    insertElement(list, 2, 2);
    toString(list);
    destroyList(list);
    return 0;
}
