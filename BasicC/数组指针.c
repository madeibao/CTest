


#include<stdio.h>

int main()
{
    char a[5]={'A','K','C','G','L'};    
    char (*p)[5]=&a;//&a代表的是整个数组的首地址
    printf("%c %c %c",**p,*(*p+1),*(*p+3));//输出：A K G
    return 0;
}