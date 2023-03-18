

#include<stdio.h>

int exchange(int *p1, int *p2)		//定义两个指针
{
	int temp = 0;					//定义temp用来暂存
	temp = *p1;
	*p1 = *p2 ;
	*p2 = temp;
	return 0;	
}

int main(void)
{
	int x = 2;
	int y = 3;
	printf("befor exchang: x = %d,y = %d.\n",x,y);		//数据交换前
	exchange(&x,&y);									//直接传入数据变量的地址
	printf("after exchang:x = %d,y = %d.\n",x,y);		//数据交换后
}