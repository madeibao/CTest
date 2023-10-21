
// 这道题给了我们一个数组，数组中的数字可能出现一次或两次，
// 让我们找出所有出现两次的数字，由于之前做过一道类似的题目Find the Duplicate Number，
// 所以不是完全无从下手。
// 这类问题的一个重要条件就是1 ≤ a[i] ≤ n (n = size of array)，不然很难在O(1)空间和O(n)时间内完成。
// 首先来看一种正负替换的方法，这类问题的核心是就是找nums[i]和nums[nums[i] - 1]的关系，
// 我们的做法是，对于每个nums[i]，我们将其对应的nums[nums[i] - 1]取相反数，
// 如果其已经是负数了，说明之前存在过，我们将其加入结果res中即可，参见代码如下：


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                res.push_back(idx + 1);
            }
            nums[idx] = -nums[idx];
        }
        return res;
    }
};

int main() {

    vector<int> nums {4,3,2,7,8,2,3,1};
    Solution s2;
    vector<int> res;
    res = s2.findDuplicates(nums);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}