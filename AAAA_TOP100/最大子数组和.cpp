


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
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

        int res = dp[0];
        for(int i=1;i<dp.size();i++) {
            res = max(res,dp[i]);
        }

        return res;
    }
};



int main() {


    return 0;
}