

// 返回的是第一个出现一次的字符的位置
// 第一个位置内容

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
	int firstUniqChar(string s) {
		for(int i=0;i<s.size();i++) {
			if(s.find(s[i])==s.rfind(s[i])) {
				return i;
			}
		}
		return -1;
	}
};

int main(int argc, char *argv[]) {

	string s ="leetcode";
	Solution s2;
	cout<<s2.firstUniqChar(s)<<endl;
	return 0;
}
