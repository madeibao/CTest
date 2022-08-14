

// O(1) 的空间复杂度

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

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
        if (nums.size()==2) {
            return max(nums[0], nums[1]);
        }

        int a = nums[0];
        int b = max(nums[0],nums[1]);

        // c 是一个临时的变量
		int c= 0;
        for(int i=2;i<nums.size();i++) {
            c = max(a+nums[i], b);
            a =b;
            b =c;
        }

        return b;
    }
};

int main(int argc, char**argv) {

	vector<int> nums = {1,2,3,1};
	Solution s;
	cout << s.rob(nums) << endl;
	return 0;
}