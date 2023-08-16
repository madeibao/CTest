

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	void sort(vector<int>& nums) {
		bool flag;
		for(int i=0;i<nums.size();i++) {
			flag = false;
			for(int j=0;j<nums.size()-i-1;j++) {
				if(nums[j]>nums[j+1]) {
					swap(nums[j],nums[j+1]);
					flag = true;
				}
			}
			if(!flag) {
				break;
			}
		}
		
	}
};


int main(int argc, char**argv) {

	vector<int> nums = {2,3,5,4,1};
	Solution s2;
	s2.sort(nums);
	for(auto i:nums) {
        cout<<i<<" ";
	}

	return 0;
}
