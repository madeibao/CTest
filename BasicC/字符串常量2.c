
#include <stdio.h>

int main() {
    char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    const char *str3 = "hello bit.";
    const char *str4 = "hello bit.";
    if(str1 ==str2)
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n");    // 输出

    if(str3 ==str4)
        printf("str3 and str4 are same\n");        // 输出
    else
        printf("str3 and str4 are not same\n");     
    return 0;
}
