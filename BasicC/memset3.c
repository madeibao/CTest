



// memset函数是C++ <string.h>头文件中的一个函数，它将从给定地址开始，
// 逐个字节刷内存，初始化它们为给定的参数。
// 基本用法：


// void *memset(void *str, int c, size_t n)

// 解释：复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。
// 作用：是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
// 头文件：C中#include<string.h>，C++中#include<cstring>
// memset函数是按一个字节一个字节来赋值的

// 因此，用memset对非字符型数组的赋值一般都是错误的(0和-1除外)。



#include<stdio.h>
#include<string.h>

int main(){
    char array[4];
    int i=0;
    memset(array,'1',4);
    for(i=0; i<4; i++){
        printf("%c ",array[i]);
    }
    printf("\n");
    return 0;
}

