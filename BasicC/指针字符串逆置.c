

#include<stdio.h>
#include<string.h>

int main()
{
	char a[100] = "hello,world";
	char *p = a;
	int len = strlen(a);

	char *p1 = p;//等同于*p1 = a;
	p1 += len -1;
	if(p<p1)
	{
		char tmp = *p;//值交换
		*p = *p1;
		*p1 = tmp;
		p1--;//地址加1减1
		p++;
	}
	printf("%s\n",a);//%s字符串
	return 0;
}