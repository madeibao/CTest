

#include <stdio.h>
int main()
{
    int array[20] = {0};
    int *ptr = array;
    for (i = 0; i < 20; i++)
    {
        (*ptr)++;
        ptr++;
    }
}