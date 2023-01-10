

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
	public:
		int rotateMin(vector<int>& nums) {
			int l = 0,r i = nums.size()-1;

			while (l < r) {
				int m = (l+r)/2;
				if(nums[mid]<nums[r]) {
					r = mid;
				}
				else {
					l = mid+1;
				}
			}
			return nums[l];
		}
};


int main(int argc, char*argv[]) {

	vector<int> nums {3,4,5,1,2};
	Solution s;
	cout<<s.rotateMin(nums)<<endl;
	return 0;
}



