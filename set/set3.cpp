



#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main() {
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(1);

    cout << *s.begin() << endl;				//返回set的第一个元素的迭代器
    cout << *(--s.end()) << endl;			//返回set最后一个元素后面一个位置的迭代器
    if (s.empty())							//判断set是否为空
        cout << "is empty" << endl;
    else
        cout << "is not empty" << endl;
    cout << s.size() << endl;				//输出set此时的元素个数
    s.clear();								//清空，删除所有元素
    cout << s.size() << endl;

    return 0;
}
