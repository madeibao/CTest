
#include "stdio.h"

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int(*pa)[10] = &arr;
	int i = 0;

	for (i = 0; i < 10; i++)
	{
	    //用法1，arr[i]变成(*p)[i]，相当于arr[i]
		printf("%d ", arr[i]);
	}

    printf("\n");
	for (i = 0; i < 10; i++)
	{
	    //用法1，arr[i]变成(*p)[i]，相当于arr[i]
		printf("%d ", (*pa)[i]);
	}

    printf("\n");

	for (i = 0; i < 10; i++)
	{
		//用法2，pa解引用为*pa，相当于arr,可以当首元素地址使用
		printf("%d ", *(*pa + i));
	}

    return 0;
}
