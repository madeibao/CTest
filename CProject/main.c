

#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;


int main(int argc, char** argv) {

	signed char c = 0xFFFE;
	printf("%d\n",c--);
	return 0;
}

/**
	由于c的内存会溢出
	只会取后面的8位

	即
	11111110

	计算机内存中补码表示
	补码取反加一

	取反，第一位位符号位，忽略
	10000001

	加一
	10000010

	则输出结果位-2

*/
