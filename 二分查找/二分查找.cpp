
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (high - low) / 2 + low;
            int num = nums[mid];
            if (num == target) {
                return mid;
            } else if (num > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};


int main() {

    vector<int> nums = {-1,0,3,5,9,12};
    int target =  9;
    Solution s2;
    cout<<s2.search(nums,target);
    return 0;
}
