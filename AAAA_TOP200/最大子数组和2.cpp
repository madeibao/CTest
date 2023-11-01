



#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

    	vector<int> dp(nums.size());

    	dp[0] = nums[0];

    	int len = dp.size();
    	for(int i=1; i < len; i++) {
    		if(dp[i-1]>0) {
    			dp[i] = dp[i-1]+nums[i];
    		}
    		else {
    			dp[i] = nums[i];
    		}
    	}

    	int res = dp[0];
    	for(int i = 1; i < len; i++) {
    		res = max(res,dp[i]);
    	}

    	return res;
    }
};

int main(int argc, char** argv) {


	vector<int> dp {-2,1,-3,4,-1,2,1,-5,4};
	Solution solution;
	cout << solution.maxSubArray(nums) << endl;
	return 0;
}