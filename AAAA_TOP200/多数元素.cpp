
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

int main(int argc, char** argv) {

	vector<int> nums {2,2,3,3,3};
	Solution solution;
	cout << solution.majorityElement(nums) << endl;
	return 0;
}

