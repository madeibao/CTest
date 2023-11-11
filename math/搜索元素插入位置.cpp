

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0, right = nums.size()-1;
        int index = -1;
        while(left<=right) {
            int temp = (left+right)/2;

            if(nums[temp] == target) {
                return temp;
            }
            else if(nums[temp]>target) {
                right = temp-1;
            }
            else if(nums[temp]<target) {
                left = temp+1;
            }
        }

        return left;
    }
};

int main(int argc, char* argv[]) {

    vector<int> nums = {1,3,5,6};
    int target = 5;
    Solution s2;
    cout<<s2.searchInsert(nums, target)<<endl;
    return 0;
}
