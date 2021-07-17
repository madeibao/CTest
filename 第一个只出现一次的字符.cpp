
// 字符串中第一个只出现一次的字符。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	char firstUniqChar(string s) {
		vector<int>res(26);
		for(char c :s) {
			res[c-'a']++;
		}
		for(char c:s) {
			if(res[c-'a']==1) {
				return c;
			}
		}
		return ' ';
	}
};

int main(int argc, char* argv[]) { 

	Solution s; 
	string str="meetcode";
	cout<<s.firstUniqChar(str)<<endl;
	return 0;
}

