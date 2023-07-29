
#include<iostream>
#include<string>

using namespace std;

int main()
{
 
 	string st1("babbabab");
    cout << st1.find('a') << endl;//1   由原型知，若省略第2个参数，则默认从位置0（即第1个字符）起开始查找
    cout << st1.find('a', 0) << endl;//1
    cout << st1.find('a', 1) << endl;//1   
    cout << st1.find('a', 2) << endl;//4
 
    return 0；
}