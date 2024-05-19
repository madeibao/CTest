


// 首先看在 C++ 17 引入的 gcd 函数（在 numeric 头文件中），一种可能的实现如下：


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	int gcda(int x, int y) {
		return __gcd(x,y);
	}
};

int main(int argc, char** argv) {

	int x = 4, y = 2;

	Solution s;
	cout<<s.gcda(x,y)<<endl;
	return 0;
}
