#include <stdio.h>

int main(int argc, char const *argv[])
{
    // void * 可以指向任何类型的变量，使用该指针所指向的内存时，最好强制转换成它本身的类型
    void *p = NULL;
    int a = 100;
    p = &a;

    *( (int *)p ) = 200;  //注意这里强制转化成 int * 类型
    printf("*p = %d\n", *((int *)p));// 输出200
    return 0;
}
