


//上图源代码
#include <stdio.h>
struct Stu
{
	char name[20];
	int age;
};

void print(struct Stu* ps) 
{
	printf("name = %s\t age = %d\n", (*ps).name, (*ps).age);
	//使用结构体指针访问指向对象的成员
	printf("name = %s\t age = %d\n", ps->name, ps->age);
}

int main()
{
	struct Stu s = { "zhangsan", 20 };
	print(&s);//结构体地址传参
	return 0;
}
