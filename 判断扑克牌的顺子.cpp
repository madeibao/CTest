

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool iswell(vector<int>& nums) {

		// 首先统计数组中的大王和小王。
		int i=0;
		while(i<nums.size()&&nums[i]==0) {
            i+=1;
		}

		// 数组中全部都是大小王
		// 返回结果为真。

		if(i==nums.size()-1) {
			return true;
		}

		// 如果后面出现重复的数字，则直接返回false
		for(int k=i;k<nums.size()-1;k++) {
			if(nums[k]==nums[k+1]) {
				return false;
			}

		}
		return nums[4] - nums[i]<=4;
	}

};


int main(int argc, char** argv) {

	vector<int> nums  {1,2,3,4,5};
	Solution s;
	cout<<s.iswell(nums)<<endl;

	return 0;
}
