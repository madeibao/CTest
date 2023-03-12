

#include<stdio.h>
#include<string.h>

int my_strlen01(char* p) {
	//计算字符串有效长度
	int i = 0;

	//字符串结束条件
	while (p[i] != '\0') {
        i++;
	}
	return i;
}

int main() {
	char* s = "hello";
	int m = my_strlen01(s);
	printf("%d", m);
}
