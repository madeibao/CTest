
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
         int n = nums.size();
        // 计算前缀和以及后缀和
        int f[n + 2], g[n + 2];
        f[0] = g[n + 1] = 0;
        for (int i = 1; i <= n; i++) f[i] = f[i - 1] + nums[i - 1];
        for (int i = n; i > 0; i--) g[i] = g[i + 1] + nums[i - 1];
        // 按题意计算答案
        vector<int> ans;
        for (int i = 1; i <= n; i++) ans.push_back(abs(f[i - 1] - g[i + 1]));
        return ans;

    }
};

int main() {

    vector<int> nums {10,4,8,3};
    Solution s2;
    vector<int> res;
    res = s2.leftRightDifference(nums);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}
