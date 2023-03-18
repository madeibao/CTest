

// 很多高级语言java c#就有字符串类型，有个string来表示字符串，用法和int很像，可用string s1="linux";来定义字符串的变量。
// c语言没有string类型，c语言中字符串是通过字符指针来间接实现的


// 二、c语言使用指针来管理字符串
// c语言定义字符串方法：char *p=“linux”;(可以说p是字符串 但实际上p只是应该字符指针，
// 本质上就是一个指针变量，只是p指向了一个字符串的起始地址而已。


#include <stdio.h>

int main()
{
        char *p="linux";    //字符串
        char a[]="linux";    //字符数组
        char str2[] = {"I am happy"};
        char str[] = {'a','b','c','\0'};
        printf("p= %s.\n",p);
        printf("a= %s.\n",a);
        printf("str = %s. \n", str);
        return 0;
}
