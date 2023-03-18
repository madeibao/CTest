
#include <stdio.h>
#define SIZE 5

int main()
{
    float arr[SIZE];
    float *p;
    //指针+-整数；指针的关系运算
    for(p = &arr[0]; p < &arr[SIZE];) {
         *p++ = 0;
    }

    for(int i=0;i<SIZE;i++) {
        printf("%f ",arr[i]);
    }
    return 0;
}

