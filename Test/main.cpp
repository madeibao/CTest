#include <iostream>

using namespace std;

int main()
{
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
