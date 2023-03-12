

#include<stdio.h>

int main(){
    int a = 10;
    int * p1 = &a;
    int ** p2 = &p1;
    printf("a: %d\n",a);        // 值
    printf("a  的地址               a    : %d\n",&a);        // 值
    printf("p1指向a地址             p1   : %d\n",p1);     // 地址
    printf("*p1指向存储值:          *p1    %d\n",*p1);   // 取值
    printf("\n");
    printf("-----------------------------------\n");
    printf("地址为--------------   &p1   %d\n",&p1);    // 地址
    printf("p2: 指向的一个地址      p2   %d\n",p2);     // 地址
    printf("地址为-------------   &*p2   %d\n",&*p2);
    printf("-----------------------------------\n");
    printf("\n");
    printf("\n");
    printf("地址为--------------      &P2   %d\n",&p2);    // 地址
    printf("\n");
    printf("\n");

    printf("地址为--------------     &*p1   %d\n",&*p1);    // 地址
    printf("*p2-----------------      p2    %d\n",*p2);    // 地址
    printf("&**p2:最终的值--------- &**p2   %d\n",&**p2);   // 地址

    printf("\n");
    printf("\n");
    printf("**p2:最终的值为           **p2  %d\n",**p2); // 取值

    return 0;
}
