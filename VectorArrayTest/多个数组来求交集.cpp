

// 在每一个数组中都出现的元素来求交集

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_set<int> res(nums[0].begin(), nums[0].end());
        for (int i = 1; i < n; ++i) {
            unordered_set<int> tmp;
            for (int num: nums[i]) {
                if (res.count(num)) {
                    tmp.insert(num);
                }
            }
            res = tmp;
        }
        vector<int> ans(res.begin(), res.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {

    vector<vector<int>> nums = {{3,1,2,4,5},{1,2,3,4},{3,4,5,6}};
    Solution s2;
    vector<int> res;
    res = s2.intersection(nums);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}
