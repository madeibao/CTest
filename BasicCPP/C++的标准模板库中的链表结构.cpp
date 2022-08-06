
#include<iostream>
#include<bits/stdc++.h>
#include <windows.h>

using namespace std;

typedef list<int> LISTINT;
typedef list<int> LISTCHAR;

int main()
{
    //用LISTINT创建一个list对象
    LISTINT listOne;
    //声明i为迭代器
    LISTINT::iterator i;

    listOne.push_front(3);
    listOne.push_front(2);
    listOne.push_front(1);

    listOne.push_back(4);
    listOne.push_back(5);
    listOne.push_back(6);

    cout << "listOne.begin()--- listOne.end():" << endl;
    for (i = listOne.begin(); i != listOne.end(); ++i)
        cout << *i << " ";
    cout << endl;

    LISTINT::reverse_iterator ir;
    cout << "listOne.rbegin()---listOne.rend():" << endl;
    for (ir = listOne.rbegin(); ir != listOne.rend(); ir++) {
        cout << *ir << " ";
    }
    cout << endl;

    int result = accumulate(listOne.begin(), listOne.end(), 0);
    cout << "Sum=" << result << endl;
    cout << "------------------" << endl;

    //用LISTCHAR创建一个list对象
    LISTCHAR listTwo;
    //声明i为迭代器
    LISTCHAR::iterator j;

    listTwo.push_front('C');
    listTwo.push_front('B');
    listTwo.push_front('A');

    listTwo.push_back('D');
    listTwo.push_back('E');
    listTwo.push_back('F');

    cout << "listTwo.begin()---listTwo.end():" << endl;
    for (j = listTwo.begin(); j != listTwo.end(); ++j)
        cout << char(*j) << " ";
    cout << endl;

    j = max_element(listTwo.begin(), listTwo.end());
    cout << "The maximum element in listTwo is: " << char(*j) << endl;
    Sleep(100);
    return 0;
}
