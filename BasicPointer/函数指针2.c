

#include<stdio.h>

int (*p)(int a, int b);
int func(int a,int b) {
    return a+b;
}

int main() {

    p = func;
    int res = p(2,3);
    printf("%d\n",res);

    return 0;
}
