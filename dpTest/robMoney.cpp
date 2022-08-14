
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

    	vector<int> dp(nums.size(),0);

    	if(nums.size()==0) {
    		return 0;
    	} 

    	if(nums.size()==1) {
    		return nums[0];
    	}

    	if(nums.size()==2) {
    		return max(nums[0],nums[1]);
    	}

    	dp[0] = nums[0];
    	dp[1] = max(nums[1],nums[0]);

    	for(int i=2;i<nums.size();i++) {
    		dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
    	}

    	return dp[num.size()-1];
    }
};

int main(int argc, char**argv) {

	vector<int> nums = {1,2,3,1};
	Solution s;
	cout << s.rob(nums) << endl;
	return 0;
}