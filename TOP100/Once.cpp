


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num=nums[0];
    	for(int i=1; i<nums.size(); i++) {
    		num = num^nums[i];
    	}
    	return num;
    }
};

int main(int argc, char** argv) {

	vector<int> nums { 2,2,1};
	Solution solution;
	cout << solution.singleNumber(nums) << endl;
	return 0;
}