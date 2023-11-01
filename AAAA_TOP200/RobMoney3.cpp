

// 围成一圈打家劫舍

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.size()==0) {
			return 0;
		}

		if(nums.size()==1){
			return nums[0];
		}

		if(nums.size()==2){
			return max(nums[0], nums[1]);
		}

		return max(helper(nums,0,nums.size()-2),helper(nums,1,nums.size()-1));

	}

	int helper(vector<int>& nums, int left ,int right) {
		if(left==right) {
			return nums[left];
		}

		int pre = 0;
		int cur = nums[left];

		//
		for(int i= left+1;i<=right;i++) {
			int temp = cur;
			cur = max(cur, pre+nums[i]);
			pre = temp;
		}
		return cur;
	}
};

int main(int argc, char** argv) {

	vector<int> nums {1,2,3,1};
	Solution solution;
	cout<< solution.rob(nums)<<endl;
	return 0;
}
