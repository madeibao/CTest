

//----------------------------------------------------------------
//判断数组中的一个数字出现的次数



#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int left = 0;
    	int right = nums.size()-1;

    	while (left < right) {
    		int mid = left + (right - left) / 2;

    		if(nums[mid]>=target) {
    			right = mid;
    		}
    		else {
    			left = mid+1;
    		}
    	}

    	int count =0;
    	while (left < nums.size()&& nums[left]==target) {
    		count++;
    		left++;
    	}

    	return count;
    }
};



int main(int argc, char **argv) {
	vector<int> nums = {5,7,7,8,8,10};
	int target(8);
	Solution s2;
	cout<<s2.search(nums, target)<<endl;

	return 0;
}