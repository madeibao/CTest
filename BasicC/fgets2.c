


#include "stdio.h"
int main()
{
    char st[15];
    printf("input string:\n");
    fgets(st,15,stdin); /*stdin 意思是键盘输入*/
    fputs(st,stdout);   /*stdout标准输出*/
    return 0;
}

