

#include<stdio.h>
#include<stdlib.h>

int main() {
    int * p =(int *)malloc(sizeof(int));
    if(p!=NULL) {
        *p=10;
        printf("%d",*p);
        free(p);
        p=NULL;
    }
    else {
        printf("空间分配失败");
    }
}
