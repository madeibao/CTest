

#include <stdio.h>

struct stu {
	char name[20];
	char sex;
	int num;
};

void print2(struct stu* p2)  //用一个指针p2，来接收结构体s2的地址
{   //用来打印结构体成员的函数
	printf("%s\n", p2->name);  //p2指向name
	printf("%c\n", p2->sex);   //p2指向sex
	printf("%d\n", p2->num);   //p2指向num
}

int main() {
	
	struct stu s2 = { "zhangsan", 'm', 1234 };
	print2(&s2);  //把s2的地址传过去
	return 0;
}


