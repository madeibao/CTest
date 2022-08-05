
#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

		int res = nums[0];
        int sum = 0;
        for (int num : nums) {
            if (sum > 0)
                sum += num;
            else
                sum = num;
            res = max(res, sum);
        }
        return res;
    }
};

int main(int argc, char** argv) {

	vector<int> res {-2,1,-3,4,-1,2,1,-5,4};
	Solution s2;
	cout<<s2.maxSubArray(res)<<endl;
	return 0;
}