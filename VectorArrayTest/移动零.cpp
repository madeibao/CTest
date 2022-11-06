


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

    	int i, j=0;
    	for(int i=0; i<nums.size(); i++) {
    		if(nums[i]!=0) {
    			nums[j++] = nums[i];
    		}
    	}

    	while(j<nums.size()) {
    		nums[j++]= 0;
    	}
    }
};



int main(int argc, char** argv) {

	Solution s;
	vector<int> nums = {0,1,0,3,12};
	vector<int> res;
	s.moveZeroes(nums);

	for(auto i:nums) {
		cout<<i<<" ";
	}
	return 0;
}
