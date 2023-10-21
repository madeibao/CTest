

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();++i){
            //未访问的位置全为正，如果发现已经置负的位置，即重复元素
            if(nums[abs(nums[i])-1]<0) {
                ans=abs(nums[i]);
                break;
            }
            //当前值对应下标位置置负
            nums[abs(nums[i])-1]= -nums[abs(nums[i])-1];
        }
        return ans;
    }
};


int main() {
    
    vector<int> nums {1,3,4,2,2};
    Solution s2;
    cout<<s2.findDuplicate(nums)<<endl;

    return 0;
}