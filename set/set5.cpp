
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main() {
    set<int> s;
    s.insert(12);
    s.insert(8);
    s.insert(10);
    s.insert(9);

    cout<<*prev(s.end())<<endl;    // 12 最后一个元素
    return 0;
}

//------------------------------------------------------------------------------------------


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main() {
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(1);
    s.insert(7);

    cout<<*(s.end())<<endl;    // 5 表示的是迭代器元素，第5个位置元素。
    return 0;
}
