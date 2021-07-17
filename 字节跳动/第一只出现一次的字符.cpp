


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    char firstUniqChar(string s) {

    	vector<int> ans(26);

    	for(char c:s) {
    		ans[c-'a']++;
    	}


    	for(char c:s) {
    		if(ans[c-'a'] ==1) {
    			return c;
    		}
    	}

    	return ' ';
    }
};


int main(int argc, char* argv[])  {
	string str = "leetcode";
	Solution s;
	cout<<s.firstUniqChar(str)<<endl;

	return 0;
}