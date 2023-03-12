
#include<stdio.h>

int main() {

    int array[10] = {10, 9, 8, 7};
    printf("%d\n", *array);  //  输出 10
    printf("%d\n", array[0]);  // 输出 10

    printf("%d\n", array[1]);  // 输出 9
    printf("%d\n", *(array+1)); // 输出 9

    // 用指针来指向数组的首个节点位置
    int *pa = array;
    printf("%d\n", *pa);  //  输出 10
    printf("%d\n", pa[0]);  // 输出 10

    printf("%d\n", pa[1]);  // 输出 9
    printf("%d\n", *(pa+1)); // 输出 9
    return 0;
}



