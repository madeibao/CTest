

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(), nums.end(), target);
        auto high = upper_bound(nums.begin(), nums.end(), target);
        if(low == high) {
            return {-1,-1};
        }
        return {int(low - nums.begin()), int(high - nums.begin() - 1)};
    }
};


int main() {

    Solution s2;
    vector<int> res = {5,7,7,8,8,10};
    int targe = 8;

    vector<int>res2;
    res2 = s2.searchRange(res,targe);
    for(auto i:res2) {
        cout<<i<<" ";
    }

    return 0;
}
