

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3) {
            return -1;
        }

        sort(nums.begin(), nums.end());
        int len = nums.size();

        int temp1 = nums[len - 1] * nums[len - 2] * nums[len - 3];
        int temp2 = nums[0] * nums[1] * nums[len - 1];

        return max(temp1, temp2);
    }
};

int main(int argc, char** argv) {

	Solution s;
	vector<int> nums {1,2,3,4};
	cout<<s.maximumProduct(nums)<<endl;
	return 0;
}
