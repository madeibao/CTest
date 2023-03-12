



#include<stdio.h>

int main(){

    int a = 1024;
    void *pa = &a;

//    printf("pa 指针直接使用会是什么场景%d",*pa); //报错，必须先转型
    printf("pa = %p, *pa = %d\n", pa, *((int*)pa));

    return 0;
}
