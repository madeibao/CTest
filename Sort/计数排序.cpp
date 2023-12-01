


#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // CountSort 计数排序
        int n = nums.size();
        int minNum = INT_MAX, maxNum = INT_MIN;
        // 找到数组中的最小和最大元素
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minNum) minNum = nums[i];
            if (nums[i] > maxNum) maxNum = nums[i];
        }
        // 构造计数数组
        vector<int> counts(maxNum - minNum + 1, 0);
        for (int i = 0; i < n; ++i) {
            ++counts[nums[i] - minNum];
        }
        // 计数排序
        int index = 0;
        for (int i = 0; i < counts.size(); ++i) {
            while (counts[i] != 0) {
                nums[index++] = i + minNum;
                counts[i]--;
            }
        }
        return nums;
    }
};


int main() {

    vector<int> counts = {5,2,3,1};
    Solution s2;
    vector<int> res;
    res = s2.sortArray(counts);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}