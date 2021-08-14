

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

	// C++的匿名函数
	// 最常见的写法:
	// [capture list] (params list) mutable exception-> return type { function body }

	//[捕获列表](参数列表)->返回类型{函数体}

	auto Add = [](int a, int b)->int {
		return a + b;
	};

	// 也可以写成一个更加简单的写法：

	auto Add  = [](int a,int b) {return a+b;};
	std::cout << Add(1, 2) << std::endl;
	return 0;

}
