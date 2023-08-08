

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {

	// 大顶堆写法，less 表示逐渐变小
	priority_queue<int, vector<int>,less<int> > queue2;

	queue2.push(3);
	queue2.push(1);
	queue2.push(5);
	queue2.push(8);
	queue2.push(9);


	while (!queue2.empty()) {
		cout<<queue2.top()<<" ";
		queue2.pop();
	}
	return 0;
}
