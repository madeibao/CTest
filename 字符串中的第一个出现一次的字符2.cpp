
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:	
	char firstChar(string s) {

		unsigned int ch[128] = {0};
		for(const char& c : s) {
			++ch[c];
		}

		for(unsigned int i=0;i<s.size();i++) {
			if(ch[s[i]]==1) {
				return s[i];
			}
		}
		return ' ';
	}
};


int main(int argc, char** argv) {
	string str2 ="leetcode";
	Solution s;
	cout<<s.firstChar(str2);
	return 0;
}