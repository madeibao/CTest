


#include<stdio.h>
int main(){
    int *p;  // 这里指针定义没有初始化
    *p=100;
    printf("%d",*p);
}
