

// 调整奇数字到偶数字的前面。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        unsigned int i=0, j = nums.size()-1;
        while(i<j) {
            if(nums[i]%2==0&&nums[j]%2==1) {
                swap(nums[i],nums[j]);
            }
            else {
                i++;
                j--;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums {1,2,3,4};
    vector<int> res;
    Solution s;
    res = s.exchange(nums);
    for(unsigned int i=0; i<nums.size();i++) {
        cout<<nums.at(i)<<" ";
    }
    return 0;
}
