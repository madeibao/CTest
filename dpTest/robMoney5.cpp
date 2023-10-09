

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int dp[110];
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};

int main() {

    vector<int> nums {1,2,3,1};
    Solution s2;
    cout<<s2.rob(nums)<<endl;
    return 0;
}



