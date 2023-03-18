

#include<stdio.h>
#include<stdlib.h>

int main() {
    int * p =(int *)malloc(sizeof(int)*5);
    if(p!=NULL) {
        int a = 1;
        for(int *q = p;q<p+5;q++) {
            *q=a;
            a++;
        }
        for(int *q=p;q<p+5;q++) {
            printf("%d\n",*q);
        }
        free(p);
        p=NULL;
    }
    else{
        printf("空间分配失败");
    }
}