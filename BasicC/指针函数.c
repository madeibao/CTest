

#include<stdio.h>
#include<stdlib.h>

typedef struct {
     int a;
     int b;
}Data;

//指针函数
Data* f(int a, int b)
{
     Data *data;
     data = (struct Data*)malloc(sizeof(Data));
     data->a = a;
     data->b = b;
     return data;
}

int main(int argc, const char *argv[])
{
     Data *myData = f(4, 5);
     printf("函数调用f(4,5) = %d,%d", myData->a, myData->b);

     return 0;
}




