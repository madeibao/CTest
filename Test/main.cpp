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

    //ptr = sss;  ������ʾptrΪֻ������
}
