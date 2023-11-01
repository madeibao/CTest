
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        int step = 0;
        int n = nums.size(), last = 0, cur = 0;
        for(int i=0;i<n-1;i++) {
            cur = max(cur, i+nums[i]);
            if(i==last) {
                last = cur;
                ++step;
                if(cur>=n-1) {
                    break;
                }
            }
        }

        return step;

    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution s2;
    cout<<s2.jump(nums)<<endl;

    return 0;
}