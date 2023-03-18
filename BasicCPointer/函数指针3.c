

#include <string.h>
/**
*	定义一个方法，传入两个字符串和一个函数指针 p，用 p 对两个字符串进行操作
*/
void check(char *x, char *y, int (*p)());

void main(){
	//string.h 库中的函数，使用之前需要声明该函数。字符串比较函数
	int strcmp();
	char x[] = "Zack";
	char y[] = "Rudy";
	
	//定义一个函数指针
	int (*p)() = strcmp;

	check(x, y, p);
}
void check(char *x, char *y, int (*p)()){
	if(!(*p)(x, y)){
		printf("相等");
	}else{
		printf("不相等");
	}
}
