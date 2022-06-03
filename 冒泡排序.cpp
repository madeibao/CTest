

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

void bubbleSort(vector<int>& nums) {
	if(nums.size()==0) {
		return;
	}

	for(int i=0;i<nums.size()-1;i++) {
		for(int j=0;j<nums.size()-1-i;j++) {
			if(nums[j]>nums[j+1]) {
				int temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}
}

int main(int argc, char** argv) {

	vector<int> nums = {2,3,1,4,2,5};
	bubbleSort(nums);

	for(int i:nums) {
		cout<<i<<endl;
	}
	return 0;
}