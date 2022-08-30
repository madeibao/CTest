

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	void sort(vector<int>& nums) {

		for(int i=0;i<nums.size();i++) {
			bool flag = false;

			for(int j=0;j<nums.size()-1-i;j++) {
				if(nums[j]>nums[j+1]) {
					int temp = nums[j];
					nums[j] = nums[j+1];
					nums[j + 1] = temp;
					flag = true;
				}
			}
			if(!flag) {
				break;
			}
		}
	}
};


int main(int argc, char **argv) {

	vector<int> nums {2,3,2,12,19,23};
	Solution s2;
	s2.sort(nums);
	for(int i:nums) {
		cout<<i<<" "<<endl;
	}
	return 0;
}