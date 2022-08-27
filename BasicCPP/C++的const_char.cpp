

// 使用泛型来实现C++的编程。
零、看谁在const后面，谁在const后面，就代表谁被const修饰，谁就被限定死，不可改。

	 const char *p -> *p 被修饰，*p（值）不可改；

	 char * const p -> p 被修饰， p（指针）不可改；



const char * 、char const *
这两者是等价的。当我们使用char const *定义一个指针变量时，
我们可以使这个指针变量指向别的char型的变量，但不能通过指针来修改这个char的值。
但是可以使这个指针指向别的变量。例如：

#include <iostream>
 
using namespace std;
 
int main()
{
    int i;
    char str[] = "hello world";
    char sss[] = "goood jobbb";
    char const *ptr = str;
    //const char * ptr = str'; 上下效果一样
    for(i=0; i<11; i++)
        cout << ptr[i];
    cout << endl;
 


    //ptr[0] = 's'; 报错，提示*ptr为只读对象
    //可通过str[]来修改，但是不能通过*ptr
    str[0] = 'g';
    for(i=0; i<11; i++)
        cout << ptr[i];
    cout << endl;
 
    ptr = sss;
    for(i=0; i<11; i++)
        cout << ptr[i];
    cout << endl;
}

以上的运行结果为

hello world
hello world

goood jobbb


// #-------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------



2、char * const ptr
      定义了一个指向字符的指针常数，即const指针，ptr本身的值不能被修改（即指针存储的地址是固定的），
      但是其指向的值可以被修改。

        测试代码如下
		定义一个指向字符的指针常数，即const指针，实验得知，不能修改ptr指针，但是可以修改该指针指向的内容。
		实验如下：



#include <iostream>
 
using namespace std;
 
int main() {
    int i;
    char str[] = "hello world";
    char sss[] = "goood jobbb";
    char * const ptr = str;
 
    for(i=0; i<11; i++)
        cout << ptr[i];
    cout << endl;
 
    ptr[0] = 's';
    for(i=0; i<11; i++)
        cout << ptr[i];
    cout << endl;
 
    //ptr = sss;  报错，提示ptr为只读对象
}

运行结果为：


hello world
sello world   