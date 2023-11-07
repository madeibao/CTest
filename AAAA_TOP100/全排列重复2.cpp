
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    void dfs(vector<int> nums, int x) {
        if (x == nums.size() - 1) {
            res.push_back(nums);      // 添加排列方案
            return;
        }

        set<int> set2;
        for (int i = x; i < nums.size(); i++) {
            if(set2.find(nums[i])!=set2.end()) {
                continue;
            }
            set2.insert(nums[i]);
            swap(nums[i], nums[x]);   // 交换，将 nums[i] 固定在第 x 位
            dfs(nums, x+1);           // 开启固定第 x + 1 位元素
            swap(nums[i], nums[x]);   // 恢复交换
        }
    }
};

int main() {

    vector<int> nums {1,1,3};
    vector<vector<int>> res;
    Solution s2;
    res = s2.permute(nums);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
