

// 返回的是第一个出现一次的字符

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        for(int i=0;i<s.size();i++) {
            if(s.find(s[i])==s.rfind(s[i])) {
                return s[i];
            }
        }
        return ' ';
    }
};

int main(int argc, char *argv[]) {

    string s ="ABCDleetcode";
    Solution s2;
    cout<<s2.firstUniqChar(s)<<endl;
    return 0;
}
