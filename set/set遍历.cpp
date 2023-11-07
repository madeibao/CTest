



#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main() {
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(1);


    auto it = s.end();
    it--;
    it--;
    cout<<"-------------------"<<endl;
    cout<<*it<<endl;

    return 0;
}


// 倒数第2个数字