

// ----------------------------------------------------------------
// 最好就是定义一个状态 NULL


#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p=NULL;
    if(p!=NULL){
        printf("%d",*p);
    }else{
        printf("无效指针");
    }
}
