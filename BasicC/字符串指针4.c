

#include "stdio.h"

int len(const char *str) {

    const char *p = str;
    while (*p!='\0') {
        p++;
    }
    return p - str;
}
int main(int argc, char** argv) {

    const char* str = "hello world";
    int lena = 0;
    lena = len(str);
    printf("%d\n", lena);

    return 0;
}
