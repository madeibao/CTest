
#include <stdio.h>

int main(void)
{
    int array[5];
    int *p;
    int i;

    /* 对数组array设置值 */
    for (i = 0; i < 5; i++) {
        array[i] = i;
    }

    p = array;   /* 把&array[0]替换成array */
    for (i = 0; i < 5; i++) 
    {
        printf("%d\n", *(p + i));  
    }
    
    return 0;
}