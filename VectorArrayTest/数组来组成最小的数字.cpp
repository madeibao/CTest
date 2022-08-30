

// 数组来组成的最小的数字。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	string minNum(vector<int>& nums) {	
		if(nums.size()==0) {
			return nullptr;
		}

		vector<string> strs;
		for(unsigned int i = 0; i < nums.size();i++) {
			strs.push_back(to_string(nums[i]));
		}

		sort(strs.begin(), strs.end(),[](string o1,string o2){return o1+o2<o2+o1;});
		string res;
		for(unsigned int i = 0; i < strs.size(); i++) {
			res += strs[i];
		}
		return res;

	}
};


int main(int argc, char** argv ) {

	Solution s;
	vector<int> temp = {10,2};
	cout<<s.minNum(temp);
	return 0;
}