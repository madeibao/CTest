

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int i = 0;
        while( nums[i]!=i ){
            if( nums[i]>i ){
                if(nums[i]>=nums.size())
                    return -1;
                i = nums[i];
            }
            if( nums[i]<i )
                i++;
        }
        return i;
    }
};


int main(int argc, char** argv) {

    vector<int> nums = {0,2,3,4,5};
    Solution s2;
    cout<<s2.findMagicIndex(nums)<<endl;
    return 0;
}


