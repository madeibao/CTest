

// set的默认集合是有序的。
// 集合的序列是有序的。

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    set<string> set2;

    set2.insert("a");
    set2.insert("mn");
    set2.insert("bb");

    for(string s2:set2) {
        cout<<s2<<endl;
    }
    return 0;
}



