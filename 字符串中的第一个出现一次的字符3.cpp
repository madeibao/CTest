

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {

        // 设置的基本大小为26个字符。
        vector<int> res(26,0);

        for(char c:s) {
            res[c-'a']+=1;
        }

        for(char c:s) {
            if(res[c-'a']==1) {
                return c;
            }
        }
        return ' ';
    }
};



int main(int argc, char*argv[]) {

    string str2 = "leetcode";
    Solution s;
    cout<<s.firstUniqChar(str2)<<endl;
    return 0;
}
