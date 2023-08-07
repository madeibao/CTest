

#include<iostream>
using namespace std;

class Base
{
public:
    // 声明为Virtual方法了，父类和子类有差别
	virtual void print()
	{
		cout<<"Base"<<endl;
	}
};

class Son: public Base
{
public:
	void print()
	{
		cout<<"Son"<<endl;
	}
};

void fun(Base *obj)
{
	obj->print();
}

int main()
{
	Base base;
	Son son;
	fun(&base);
	fun(&son);
	return 0;
}
