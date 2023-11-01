

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) {
                return true; // 说明可以覆盖到终点了
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution s2;
    cout<<s2.canJump(nums)<<endl;
    return 0;
}
