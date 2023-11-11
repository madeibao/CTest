

#include <iostream>
#include <string>
using namespace std;
 
int main(int argc, char *argv[])
{
    int a;
    size_t pos = 0;
    string str;
 
    str = "-1235";
    a = stoi(str);
    cout << "a = " << a << endl; //a = -1235
 
    str = "1235";
    a = stoi(str);
    cout << "a = " << a << endl; //a = 1235
 
    str = "  -12  35"; 
    a = stoi(str, &pos); //会舍弃空白符
    cout << "a = " << a << endl; //a = -12
    cout << "pos = " << pos << endl; //pos = 5
 
    str = "  -12ab35";
    a = stoi(str, &pos);
    cout << "a = " << a << endl; //a = -12
    cout << "pos = " << pos << endl; //pos = 5
 
    str = "0123";
    a = stoi(str);
    cout << "a = " << a << endl; //a = 123
 
    str = "0x123";
    a = stoi(str);
    cout << "a = " << a << endl; //a = 0
 
    return 0;
}