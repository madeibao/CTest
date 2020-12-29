/**
#include <iostream>
#include <stdlib.h>
#include<vector>
using namespace std;

class Solution {
public:
int removeDuplicates(vector<int>& nums) {
    int ret = nums.size();
    if (ret < 2)
        return ret;
    for (int i = 1; i < ret;) {
        if (nums[i] == nums[i - 1]) {
            for (int j = i; j < ret - 1; ++j) {
                swap(nums[j], nums[j + 1]);
            }
            --ret;
        } else {
            ++i;
        }
    }
    return ret;
}
};

int main() {
    Solution s;
    vector<int> nums = {1,1,2};
    int res = s.removeDuplicates(nums);
    cout<<res<<endl;
}


*/
