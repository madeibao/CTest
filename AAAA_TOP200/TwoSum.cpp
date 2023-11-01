

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                   return {i,j};
                }
            }
        }
        return {i,j};
    };
};


int main(int argc, char** argv) {

	vector<int> nums {2,7,11,15};
	int target = 9;
	vector<int> res;
	Solution solution;
	res = solution.twoSum(nums, target);
	for(int i:res) {
		cout<<i<<" ";
	}
	return 0;

}
