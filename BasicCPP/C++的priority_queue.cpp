/**

一，priority_queue
对于这个模板类priority_queue，它是STL所提供的一个非常有效的容器。

作为队列的一个延伸，优先队列包含在头文件 <queue> 中。

优先队列介绍

优先队列是一种比较重要的数据结构，它是有二项队列编写而成的，可以以O(log n) 的效率查找一个队列中的最大值或者最小值，
其中是最大值还是最小值是根据创建的优先队列的性质来决定的。

模板参数

优先队列有三个参数，其声明形式为：

priority_queue< type, container, function >
这三个参数，后面两个可以省略，第一个不可以。

其中：

ype：数据类型；
container：实现优先队列的底层容器；
function：元素之间的比较方式；
对于container，要求必须是数组形式实现的容器，例如vector、deque，而不能使list。

在STL中，默认情况下（不加后面两个参数）是以vector为容器，以 operator< 为比较方式，
所以在只使用第一个参数时，优先队列默认是一个最大堆，每次输出的堆顶元素是此时堆中的最大元素。



大顶堆
//构造一个空的优先队列（此优先队列默认为大顶堆）
priority_queue<int> big_heap;   

//另一种构建大顶堆的方法
priority_queue<int,vector<int>,less<int> > big_heap2;   

//------------------------------------------------------------
小顶堆
//构造一个空的优先队列,此优先队列是一个小顶堆
priority_queue<int,vector<int>,greater<int> > small_heap;   


priority_queue<int, vector<int>, less<int> > q;    //less<int>表示数字大的优先级越大，而greater<int>表示数字小的优先级越大

priority_queue<int, vector<int>, greater<int> > q;    //vector<int>是用来承载底层数据结构堆（heap）的容器


*/
#include<iostream>
#include <queue>
#include<string>
#include<string.h>
using namespace std;

int main() {
	//对于基础类型 默认是大顶堆
	priority_queue<int> a;
	//等同于 priority_queue<int, vector<int>, less<int> > a;

	// 这样就是小顶堆
	// 好习惯  >>中间要加空格 
	priority_queue<int, vector<int>, greater<int> > c;
	priority_queue<string> b;

	for (int i = 0; i < 5; i++) {
		a.push(i);
		c.push(i);
	}

	// 降序输出
	while (!a.empty()) {
		cout << a.top() << ' ';
		a.pop();
	}
	cout << endl;

	// 升序输出
	while (!c.empty()) {
		cout << c.top() << ' ';
		c.pop();
	}
	cout << endl;

	b.push("abc");
	b.push("abcd");
	b.push("cbd");
	while (!b.empty())
	{
		cout << b.top() << ' ';
		b.pop();
	}
	cout << endl;
	return 0;
}

