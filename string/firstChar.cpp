

//-----------------------------------------------------------------------------
// 第一个唯一字符


#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++) {
            if(s.find(s[i])==s.rfind(s[i]))
            return i;
        }
        return -1;
    }
};

int main() {

	Solution s;
	string str = "leetcode";
	cout << s.firstUniqChar(str) << endl;
	return 0;

}

