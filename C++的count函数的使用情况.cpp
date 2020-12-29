

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main() {
	//count函数的用法
	vector<int> v(10);
	int a[10] = { 1, 2, 3, 4, 4, 4, 4 };
	v[0] = 1;
	v[1] = 1;
	v[2] = 1;
	v[3] = 1;
	v[4] = 1;
	v[5] = 1;
	v[6] = 6;
	v[7] = 7;
	v[8] = 8;
	v[9] = 9;
 	
 	// 第三个参数统计的是某一个数字中的个数，指的的一个具体的数字。
	//向量计数
	cout << count(v.begin(), v.end(), 1) << endl;
	cout << count(v.begin(), v.end(), 5) << endl;
	cout << count(v.begin(), v.end(), 6) << endl;
	cout << endl;
	//数组计数
	cout << count(a, a + 10, 0) << endl;
	cout << count(a, a + 10, 1) << endl;
	cout << count(a, a + 10, 4) << endl;
 
 
	system("pause");
	return 0;
}


