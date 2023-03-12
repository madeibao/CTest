

#include<stdio.h>
int main() {

    int a = 1024;
    int *pa = &a;

    printf("pa = %p\n", pa);            // 打印地址
    printf("pa = %p\n", &a);            // 打印地址
    printf("value of a is %d\n", *pa);  // 打印值
    printf("value of a is %d\n", a);    // 打印值
    return 0;
}
