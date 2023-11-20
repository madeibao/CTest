

// 动态规划-压缩数组

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int n = nums.size();
        int sum = 0;
        int maxs = INT_MIN;
        for(int i=0; i<n; i++){
            
            sum = max(sum + nums[i], nums[i]);
            
            maxs = max(maxs, sum);
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
