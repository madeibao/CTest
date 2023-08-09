


// decltype与auto关键字一样，用于进行编译时类型推导。
// decltype实际上有点像auto的反函数，auto可以让你声明一个变量，
// 而decltype则可以从一个变量或表达式中得到类型，例如：


#include<string> 
#include<iostream>

using namespace std;
 
class A {
public:
    static int total;
    string name;
    int age;
    float scores;
}
 
int A::total=0;

int main()
{
	int n=0;
	const int &r=n;
	A a;
	decltype(n) x=n;    //n为Int，x被推导为Int
	decltype(r) y=n;    //r为const int &，y被推导为const int &
	decltype(A::total)  z=0;  ///total是类A的一个int 类型的成员变量，z被推导为int
	decltype(A.name) url="www.baidu.com";//url为stringleix
	return 0;
}