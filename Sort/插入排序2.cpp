
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

void insertSort(vector<int>& nums) {

	if(nums.size()==0) {
		return;
	}

	for(int i=1; i<nums.size(); i++) {

		int temp = nums[i];
		int index = i-1;

		while(index>=0&&nums[index]>temp) {
			nums[index+1]= nums[index];
			index--;
		}

		nums[index+1] = temp;
	}
}

int main(int argc, char* argv[]) {

	vector<int> nums {2,1,3,4,5,2,3,4};
	insertSort(nums);

	for(int i:nums) {
		cout<<i<" ";
	}
	return 0;
}