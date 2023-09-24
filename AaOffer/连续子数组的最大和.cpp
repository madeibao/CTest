

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

    	if(nums.size()==0) {
    		return 0;
    	}

    	vector<int> dp(nums.size(),0);
    	dp[0] = nums[0];

    	for(int i=1;i<nums.size();i++) {
    		if(dp[i-1]>0) {
    			dp[i] = dp[i-1]+nums[i];
    		}
    		else {
    			dp[i] = nums[i];
    		}
    	}

    	int res = 0;
    	for(int i=0;i<dp.size();i++) {
    		res = max(res,dp[i]);
    	}
    	return res;
    }
};

int main(int argc, char** argv) {

	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s2;
	cout<<s2.maxSubArray(nums)<<endl;
	return 0;
}
