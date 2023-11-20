

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sums = 0;
        int maxSum = -0x3f3f3f3f;
        for(int i=0; i<len; i++){
            sums += nums[i];
            maxSum = max(sums, maxSum);
            if(sums <= 0){
                sums = 0;
            }
        }
        return maxSum;
    }
};

int main() {

    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    Solution s2;
    cout<<s2.maxSubArray(nums)<<endl;
    return 0;
}
