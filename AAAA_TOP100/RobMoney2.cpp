

#include<iostream>
#include<bits/stdc++.h>

usng namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};

int main(int argc, char** argv) {

	vector<int> nums = {1,2,3,1};
	Solution s2;
	cout<<s2.rob(nums)<<endl;

	return 0;
}