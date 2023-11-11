

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++) {
            if(i>0&&nums[i]==nums[i-1]) {
                continue;
            }
            for(int k=i+1;k<nums.size();k++) {
                if(k>i+1&&nums[k]==nums[k-1]) {
                    continue;
                }

                int left = k+1;
                int right = nums.size()-1;

                while(right>left) {

                    if(nums[i]+nums[k]+nums[left]+nums[right]>target) {
                        right--;
                    }
                    else if(nums[i]+nums[k]+nums[left]+nums[right]<target) {
                        left++;
                    }
                    else {
                        res.push_back(vector<int>{nums[i],nums[k],nums[left],nums[right]});
                        while(left<right&&nums[right]==nums[right-1])  right--;
                        while(left<right&&nums[left]==nums[left+1])    left++;
                        
                        left++;
                        right--;
                    }

                }
            }
        }
        return res;
    }
};

int main() {

    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res;
    Solution s2;
    res = s2.fourSum(nums,target);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
