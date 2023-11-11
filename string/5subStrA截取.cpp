



#include <iostream>
#include <string>
 
int main() {
    std::string str = "Hello, World!";
    
    // 提取从位置 7 开始的子串
    std::string sub1 = str.substr(7);
    std::cout << "sub1: " << sub1 << std::endl;  // 输出 "World!"
    
    // 提取从位置 7 开始的长度为 5 的子串
    std::string sub2 = str.substr(7, 5);
    std::cout << "sub2: " << sub2 << std::endl;  // 输出 "World"
    
    return 0;
}

//--------------------------------------------------------------------------------------------------------

// 定义
// substr()是C++语言函数，主要功能是复制子字符串，要求从指定位置开始，并具有指定的长度。如果没有指定长度_Count或_Count+_Off超出了源字符串的长度，则子字符串将延续到源字符串的结尾。——摘自百科词条

// 语法
// substr(size_type _Off = 0,size_type _Count = npos)
// 一种构造string的方法
// 形式 ： s.substr(pos, len)
// 返回值： string，包含s中从pos开始的len个字符的拷贝（pos的默认值是0，len的默认值是s.size() - pos，即不加参数会默认拷贝整个s）
// 异常 ：若pos的值超过了string的大小，则substr函数会抛出一个out_of_range异常；若pos+n的值超过了string的大小，则substr会调整n的值，只拷贝到string的末尾

// substr有2种常用用法：
// 假设：string s = “0123456789”;

// string sub1 = s.substr(5); //只有一个数字5表示从下标为5开始一直到结尾：sub1 = “56789”

// string sub2 = s.substr(5, 3); //从下标为5开始截取长度为3位：sub2 = “567”


#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s="sfsa";
	string a=s.substr(0,3);
	string b=s.substr();
	string c=s.substr(2,3);
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s = "0123456";

	string s1 = s.substr(0, 2);//从s的索引为0的位置截取2个长度的字符串
	cout << s1<<endl;//"01"

	string s2 = s.substr(2, 3);//从s的索引为2的位置截取3个长度的字符串
	cout << s2 << endl;//"234"

	string s3 = s.substr(2);//如果只提供一个索引位置信息，那么截取s索引为2到字符串尾部
	cout << s3 << endl;//"23456"

	string s4 = s.substr();//如果不提供任何信息，那么等价于s3=s
	cout << s4 << endl;//"0123456"

	string s5 = s.substr(7);//按理s的索引最多到6，但是组成字符串默认最后一位为空字符，所以索引可以到7
	cout << s5 << endl;//输出为空字符
	return 0;
}
