
accumulate带有三个形参：头两个形参指定要累加的元素范围，第三个形参则是累加的初值。
accumulate函数将它的一个内部变量设置为指定的初始值，
然后在此初值上累加输入范围内所有元素的值。accumulate算法返回累加的结果，其返回类型就是其第三个实参的类型。
可以使用accumulate把string型的vector容器中的元素连接起来：




#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int main(int argc, char** argv) {
	int arr[]={10,20,30,40,50};
	vector<int> va(&arr[0],&arr[5]);
	int sum=accumulate(va.begin(),va.end(),0);  //sum = 150
	return 0;
}
