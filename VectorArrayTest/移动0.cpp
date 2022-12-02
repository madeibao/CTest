
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
	void moveZeroes(vector<int>& nums) {

		vector<int> res(nums.size(),0);
		int i =0;
		int j =0;

		while(i < nums.size()) {
			if(nums[i]!=0) {
				nums[j++] = nums[i];
			}
			i++;
		}
		while(j < nums.size()) {
			nums[j++] = 0;
		}
	}


};

int main(int argc, char** argv) {

	vector<int> nums = {0,1,0,3,12};
	Solution s2;
	vector<int> res;
    s2.moveZeroes(nums);
	for(auto i=0;i<nums.size();i++) {
		cout<<nums[i]<<" "<<endl;
	}
	return 0;
}
