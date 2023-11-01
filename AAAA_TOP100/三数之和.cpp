

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> res;
        if(n==0) {
            return res;
        }
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++) {
            if(i>0&&nums[i]==nums[i-1]) {
                continue;
            }

            int target = -nums[i];
            int c = n-1;

            for(int b = i+1;b<n;b++) {
                if(b>i+1&&nums[b]==nums[b-1]) {
                    continue;
                }

                while(b<c&&nums[b]+nums[c]>target) {
                    c--;
                }
                if(b==c) {
                    break;
                }

                if(nums[b]+nums[c]==target) {
                    res.push_back({nums[i],nums[b],nums[c]});
                }

            }
        }
        return res;

    }
};

int main() {

    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution s2;
    vector<vector<int>> res;
    res = s2.threeSum(nums);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
