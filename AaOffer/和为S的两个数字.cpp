
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size()==1) return ans;
        int left = 0 , right = nums.size()-1;
        while(left<right) {
            if(nums[left] + nums[right] < target) {
                    left++;
            }
            else if(nums[left] + nums[right] > target) {
                right--;
            }
            else {
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                break;
            }
        }
        return ans;
    }
};

int main() {

	vector<int> nums {2,7,11,15};
	int target = 9;
	vector<int> res;
	Solution s2;
	res = s2.twoSum(nums, target);
	for(auto i:res) {
		cout<<i<<" ";
	}
	return 0;
}
