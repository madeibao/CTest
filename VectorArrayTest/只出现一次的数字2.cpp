

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; i += 3)
            if (nums[i] != nums[i + 2]) return nums[i];
        return nums.back();
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);
        for(auto num : nums) {
            for(int i=0;i<32;i++) {
                bits[i] += num & 1;
                num >>= 1;
            }
        }

        int res = 0;
        for(int i=31; i>=0; i--) {
            res <<= 1;
            res += bits[i] % 3;
        }
        return res;
    }
};


int main(int argc, char** argv) {

	vector<int> nums {2,3,3,3};
	Solution s2;
	cout<<s2.singleNumber(nums)<<endl;

	return 0;
}
