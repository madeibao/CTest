
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// C++ 来构建一个Split函数来解决字符串的分割问题

vector<string> split(string s, char token) {
    stringstream iss(s);
    string word;
    vector<string> vs;
    while(getline(iss, word,token)) {
        vs.push_back(word);
    }
    return vs;
}
int main(int argc, char *argv[]) {
    // 下面是测试用例
    string s="aaa,bbb,ccc,ddd";
    vector<string> s2 = split(s,',');
    for(unsigned int i=0;i<s2.size();i++) {
        cout<<s2[i]<<endl;
    }

    system("pause");
    return 0;
}
