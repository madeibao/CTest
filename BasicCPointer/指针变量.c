


#include<stdio.h>


int main() {
    int a = 100, b = 10;    //定义整型变量a，b并初始化
    int* p1, * p2;          //定义指向整型数据的指针变量p1，p2；
    p1 = &a;                //把变量a的地址赋给指针变量p1
    p2 = &b;                 //把变量a的地址赋给指针变量p2

    printf("a=%d,b=%d\n", a, b);//输出变量a和b的值
    printf("*p1=%d,*p2=%d\n", *p1, *p2);

}


