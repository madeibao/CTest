
#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    int a = 10, b = 20;

    swap(&a, &b);
    printf("a=%d\nb=%d\n", a, b);

    return 0;
}
void swap(int *x, int *y)
{
    int t;

    t = *x;
    *x = *y;
    *y = t;
}
