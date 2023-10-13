


// 字符串大小写转换

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main(int argc, char** argv) {

	string s= "HELLO";
	// 小写
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout << s << endl;
	// 大写
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	cout << s << endl;
	return 0;
}



// Java 内存模型

// reenLock

// Synchronized

// Java 线程池

