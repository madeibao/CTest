

#include<iostream>
#include<deque>

using namespace std;

void test07() {
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(30);
	d.push_front(40);

	//通过[]方式访问元素
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}

	cout << endl;//40 30 10 20

    cout<<"-------------------------"<<endl;
	//通过at方式访问元素
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	}
	
	cout << endl;
    cout<<"-------------------------"<<endl;

	cout << "第一个元素:" << d.front() << endl;//40
	cout << "最后一个元素:" << d.back() << endl;//20

}

int main()
{
	test07();
	system("pause");
	return 0;
}
