
#include<bits/stdc++.h>
#include<iostream>

using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int m = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) {
                int t = r;
                m = max(m, t - l + 1);
                while (t + 1 < nums.size() && nums[t+1] == 1) {
                    t++;
                    m = max(m, t - l + 1);
                }
                if (t == nums.size()) {
                    break;
                }
                l = r + 1;
                r++;
            } else {
                r++;
                m = max(m, r - l);
            }
        }
        return m;
    }
};


class Solution2 {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int dp1 = 0;
        int dp0 = 0;
        int res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                dp1 = dp1 + 1;
                dp0 = dp0 + 1;
            } else {
                dp1 = dp0 + 1;
                dp0 = 0;
            }
            res = max(dp1, max(res, dp0));
        }
        return res;
    }

};



int main() {
    vector<int> nums {1,0,1,1,0};
    Solution s2;
    cout<<s2.findMaxConsecutiveOnes(nums)<<endl;

    return 0;
}