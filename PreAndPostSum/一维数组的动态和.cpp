


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};


int main(int argc, char* argv[]) {


	vector<int> nums = {1,2,3,4};
	Solution s2;
	vector<int> res;
	res = s2.runningSum(nums);
	for(auto i:res) {
		cout<<i<<endl;
	}
	return 0;
}