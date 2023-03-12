

#include<stdio.h>
void f(int **ptr){//ptr初始化为b的地址
    *ptr=NULL;//对ptr进行间接访问，得到的是指针b，把它赋值为NULL
}
int main(void){
    int a=1;
    int *b=&a;
    printf("a的地址为：%d\n",&a);//打印a的地址
    printf("b的值为：  %d\n",b);//此时b指向a，打印的是a的地址
    f(&b);
    printf("b的值为：%d\n",b);//此时指针b的值已经改变了，为NULL
}
