

//C++ STL program to demonstrate example of
//vector::back() function

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1{ 10, 20, 30, 40, 50 };

    //accessing last element
    //using vector::back() function

    cout << "last element is:" << v1.back() << endl;

    //changing last element
    v1.at(v1.size() - 1) = 100;
    cout << "now, last element is:" << v1.back() << endl;

    //changing last element
    //using push_back()
    v1.push_back(200);
    cout << "now, last element is:" << v1.back() << endl;

    return 0;
}