


#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
	vector<vector<int>> helper(vector<int> nums) {
		vector<vector<int>> res;
		if(nums.size()==0) {
			return res;
		}

		helper(res, nums, 0, nums.size());
		return res;
	}

	void helper(vector<vector<int>> &res, vector<int>nums, int start, int end) {
		if(start==end) {
			res.push_back(nums);
		}

		for(int i=start; i<end; i++) {
			swap(nums[start],nums[i]);
			helper(res,nums, start+1, end);
			swap(nums[start],nums[i]);
		}
	}

};


int main(int argc, char** argv) {


	vector<int> nums {1,2,3};
	vector<vector<int>> res;
	Solution s;
	res = s.helper(nums);
	for(auto i:res) {
		for(int j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
