
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p = (int *)malloc(sizeof(int));
    *p=10;
    free(p);  // 同样是野指针,指针资源释放了。
    printf("%d",*p);
}
