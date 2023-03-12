
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p = (int *)malloc(sizeof(int));  // 这里指针定义并且进行初始化操作
    *p=10;
    printf("%d",*p);
}