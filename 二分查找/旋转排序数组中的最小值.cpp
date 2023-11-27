
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0,right = nums.size()-1;

        while(left<right) {

            int mid = (left+right)/2;

            if(nums[mid]<nums[right]) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }

        return nums[left];
    }
};

int main() {

    vector<int> nums = {3,4,5,1,2};
    Solution solution;
    cout<<solution.findMin(nums)<<endl;
    return 0;
}
