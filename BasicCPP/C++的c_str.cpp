


//标准库的string类提供了三个成员函数来从一个string得到c类型的字符数组
//主要介绍c_str
//c_str()：生成一个const char*指针，指向以空字符终止的数组。
//这个数组应该是string类内部的数组
#include <iostream>
//需要包含cstring的字符串
#include <cstring>
using namespace std;
 
int main()
{
	//更好的方法是将string数组中的内容复制出来 所以会用到strcpy()这个函数
	char *c = new char[20];
	string s = "1234";
	// c_str()返回一个客户程序可读不可改的指向字符数组的指针，不需要手动释放或删除这个指针。
	strcpy(c,s.c_str());
	cout<<c<<endl;
	s = "abcd";
	cout<<c<<endl;
}


//------------------------------------------------------------------------------------------------


//标准库的string类提供了三个成员函数来从一个string得到c类型的字符数组
//主要介绍c_str
//c_str()：生成一个const char*指针，指向以空字符终止的数组。
//这个数组应该是string类内部的数组
#include <iostream>
//需要包含cstring的字符串
#include <cstring>
using namespace std;
 
int main()
{
	//更好的方法是将string数组中的内容复制出来 所以会用到strcpy()这个函数
	char *c = new char[20];
	string s = "1234";
	// c_str()返回一个客户程序可读不可改的指向字符数组的指针，不需要手动释放或删除这个指针。
	strcpy(c,s.c_str());
	cout<<c<<endl;
	s = "abcd";
	cout<<c<<endl;
}