


#include <iostream>

using namespace std;

void test05()
{
	cout << "test05" << endl;
	int c = 20;
	int d = 30;
	auto Add = [&](int a, int b) {
		cout << "c = " << c << endl;
		cout << "d = " << d << endl;
		return c;
	};

	d = 10;//在这里修改d的值，会改变Add里的d值吗？

	cout << Add(1, 2) << endl;
}

void test06()
{
	cout << "test06" << endl;
	int c = 20;
	int d = 30;
	auto Add = [=](int a, int b) {
		cout << "c = " << c << endl;
		cout << "d = " << d << endl;
		return c;
	};

	d = 10;//在这里修改d的值，会改变Add里的d值吗？

	cout << Add(1, 2) << endl;
}

int main(int argc,char **argv)
{

	//test01();
	//test02();
	//test03();
	test05();
    cout<<"--------------------------------"<<endl;
	test06();

	return 0;
}
