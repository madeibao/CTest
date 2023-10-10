

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        for(auto& n:nums) sum += n;
        int r = sum, l = 0;
        for(int i=0; i<nums.size(); ++i) {
            r -= nums[i];
            if(l == r) return i;
            else l += nums[i];
        }
        return -1;
    }
};


int main() {

    vector<int> nums {2,3,-1,8,4};
    Solution s2;
    cout<<s2.findMiddleIndex(nums)<<endl;

    return 0;
}
