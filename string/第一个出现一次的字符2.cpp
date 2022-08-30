

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution 	{
	public:
		char first(string str) {
			vector<int> nums(26,0);
			for(char c:str) {
				nums[c-'a']+=1;
			}

			for(char c:str) {
				if(nums[c-'a']==1) {
					return c;
				}
			}
			return ' ';
		}
};


int main(int argc, char** argv) {

	Solution s;
	string str = "leetcode";
	cout<<s.first(str)<<endl;
	return 0;
}
