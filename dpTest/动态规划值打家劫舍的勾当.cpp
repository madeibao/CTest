

// 所有的房屋都围成一圈来进行打家截舍得行为。

#include<iostream>
#include<bits/stdc++.h>
using  namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		return max(myRob(vector<int>(nums.begin(), nums.end() - 1)), myRob(vector<int>(nums.begin() + 1, nums.end())));
	}
private:
	int myRob(vector<int> nums) {
        if(nums.size()==0) {
            return 0;
        }
        if(nums.size()==1) {
            return nums[0];
        }
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2;i<nums.size();i++) {
            dp[i] = max(dp[i-2]+nums[i],nums[i-1]);
        }
        return dp[nums.size()-1];
	}
};

int main(){
    vector<int> res {1,2,3,1};
    Solution s;
    cout<<s.rob(res)<<endl;
    return 0;
}


