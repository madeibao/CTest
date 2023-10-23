
#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int fast = 0;
        int slow = 0;

        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast==slow) {
                break;
            }
        }

        fast = 0;
        while (nums[fast]!=nums[slow]) {
            slow=nums[slow];
            fast=nums[fast];
        }
        return nums[slow];

    }
};

int main(int argc, char** argv) {

    vector<int> nums = {1,2,3,4,2};
    Solution solution;
    cout<<solution.findDuplicate(nums)<<endl;
    return 0;
}
