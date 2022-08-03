#include "stdio.h"
#include "stdlib.h"

#define PI 3.14 // #define 宏名 宏值(定义常量大写)
void main()
{
    int a = 10; //类型名 变量名 = 变量值(定义变量用小写)
    char b;     //没有变量值的变量定义叫做声明(定义会开辟内存空间，声明则不会)

    //变量要想使用必须有定义，如果没有看到变量定义，编译器会自动找寻一个变量声明提升成为定义
    //如果该变量的声明前有 extern 关键字，无法提升
    //提升为定义的声明系统会给局部变量赋予一个随机值,全局变量和静态变量如果未初始化则默认为0
    b = 'a';

    printf("%d\n", b); //返回值为字符对应的ASCII码('A'：65, 'a'：97, '0'：48, '\n':10, '\0': 0)

    printf("此类型的大小为%d\n", sizeof(int));       // sizeof求变量或类型大小，返回无符号整型(int 4字节)
    printf("此类型的大小为%d\n", sizeof(short));     // 2字节
    printf("此类型的大小为%d\n", sizeof(long));      // windows: 32/64: 4字节； Linux：32位:4字节， 64位:8字节
    printf("此类型的大小为%d\n", sizeof(long long)); // 8
    printf("\\n\n");                                 // '\'	将普通字符转为 特殊意 将特殊字符转为本身意
    // system("pause");
    // getchar();
}
