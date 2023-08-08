

#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

void printdeque6(const deque<int>& d)
{
	for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test08()
{
	deque<int>d1;

	//尾插
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	printdeque6(d1);//300 200 100 10 20 30

	//排序
	//对于支持随机访问的迭代器，都可以利用sort算法来对其直接进行排序
	//vector容器也可以利用sort来进行排序
	sort(d1.begin(), d1.end());//从小到大
	cout << "排序后" << endl;
	printdeque6(d1);

}
int main()
{
	test08();
	system("pause");
	return 0;
}
