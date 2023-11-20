



#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(i<=k) {
            if(nums[i]==0) {
                swap(nums[i++],nums[j++]);
            }
            else if(nums[i]==2) {
                swap(nums[i++],nums[k--]);
            }
            else {
                i++;
            }
        }
    }
};


int main(int argc, char** argv) {


    vector<int> nums = {2,0,2,1,1,0};
    Solution s2;
    s2.sortColors(nums);
    for(auto i:nums) {
        cout<<i<<" "<<endl;
    }
    return 0;
}