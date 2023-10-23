

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int left = 0;
    	int right = nums.size()-1;

    	while (left <= right) {

    		int mid = (left + right) / 2;

    		if(nums[mid] == target) {
    			return mid;
    		}
    		if(nums[left]<=nums[mid]) {
                // 在左侧范围搜索
    			if(nums[left]<=target&&target<nums[mid]) {
    				right = mid-1;
    			}
    			else {
    				left = mid + 1;
    			}
    		}
    		else {

    			// 在右侧范围之内来进行搜索
    			if(nums[mid]<target&&target<=nums[right]) {
    				left = mid + 1;
    			}
    			else {
    				right = mid -1;
    			}
    		}
    	}

    	return -1;
   	}
};



int main() {
	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 0;
	Solution s2;
	cout<<s2.search(nums,target)<<endl;
    return 0;
}
