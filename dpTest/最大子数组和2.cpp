
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);

        dp[0] = nums[0];
        int maxs = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            if(i>0) {
                dp[i] = max(dp[i-1] + nums[i], nums[i]);
            }
            else {
                dp[i] = nums[i];
            }
            maxs = max(maxs, dp[i]);
        }

        return maxs;
    }
};

int main() {

    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    Solution s2;
    cout<<s2.maxSubArray(nums)<<endl;
    return 0;
}
