

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {

    	vector<string> strs;

    	for(unsigned int i = 0; i < nums.size();i++) {
    		strs.push_back(to_string(nums[i]));
    	}

    	sort(strs.begin(), strs.end(),helper);

    	string res = "";
    	for(unsigned int i = 0; i < strs.size();i++) {
    		res += strs[i];
    	}

    	return res;
    }

    static bool helper(const string &a, const string &b) {
    	return a+b<b+a;
    }

};


int main(int argc, char** argv) {

	vector<int> nums = {12,21};
	Solution s2;
	cout<<s2.minNumber(nums)<<endl;
	return 0;
}