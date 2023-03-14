

#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 1. 指针的加法，不是传统的加法
    // 2. 步长由指针指向的数据类型来决定  int:4 , char:1
    int a;
    int *p = &a;
    printf("p: %d, p+1 : %d\n", p, p+1);

    char b;
    char *q = &b;
    printf("q: %d, q+1 : %d\n", q, q+1);
    return 0;
}
 