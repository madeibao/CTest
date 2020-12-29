
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int firstChar(string s) {
		for(unsigned int i=0;i<s.size();i++) {
			if(s.find(s[i])==s.rfind(s[i]))  {
				return i;
			}
		}
		return -1; 
	}
};


int main(int argc, char *argv[]) {

	string s2 = "leetcode";
	Solution s3;
	cout<<s3.firstChar(s2)<<endl;
	return 0;
}