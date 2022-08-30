



#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {

			int fast=0,slow=0;
			while(fast<nums.size()) {
				if(nums[fast]!=val) {
					nums[slow++]=nums[fast];
				}
                fast++;
			}

			return slow;
		}
};


int main() {

	vector<int> nums = {2,3,3,3,2};
	int num = 2;
	Solution s;
	cout<<s.removeElement(nums, num)<<endl;
	return 0;
}
