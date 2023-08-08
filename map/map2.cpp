#include <iostream>
using namespace std;

//加号运算符重载

//1.成员函数重载
class Person
{
public:
	//成员函数实现 + 号运算符重载
	Person operator+(Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}
public:
	int m_A;
	int m_B;

};

//2.全局函数重载+号
Person operator+(Person &p1,Person &p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//运算符重载 可以发生函数重载 
Person operator+(const Person& p2, int num)
{
	Person temp;
	temp.m_A = p2.m_A + num;
	temp.m_B = p2.m_B + num;
	return temp;
}

void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;

	//成员函数重载本质调用
	Person p3 = p2.operator+(p1);
	//Person p3 = p1 + p2;

	cout << "p3.m_A=" << p3.m_A << endl;//20
	cout << "p3.m_B=" << p3.m_B << endl;//20

	//全局函数重载本质调用
	Person p4 = operator+(p1, p2);
	cout << "p4.m_A=" << p4.m_A << endl;//20
	cout << "p4.m_B=" << p4.m_B << endl;//20

	Person p5 = p1 + 100;//Person+int
	cout << "p5.m_A=" << p5.m_A << endl;//110
	cout << "p5.m_B=" << p5.m_B << endl;//110
}

int main()
{
	test01();
	system("pause");
	return 0;
}


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	map<int,int> map2;

    map2.insert({2,13});
    map2.insert(pair<int,int>({1,15}));

    for(auto it = map2.begin();it!=map2.end();++it) {
        cout<<it->first<<" "<<it->second<<" "<<endl;
    }

	return 0;
}
