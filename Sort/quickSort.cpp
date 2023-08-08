

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

void quickSort(vector<int>& nums, int left, int right) {

	if(left>=right) return;

	int pivot = nums[left];
	int i = left;
	int j = right;

	while(i<j) {
		while(i<j&&nums[j]>=pivot) {
			--j;
		}
        nums[i] = nums[j];
		while(i<j&&nums[i]<=pivot) {
			++i;
		}
       	nums[j] = nums[i];
	}

	nums[i] = pivot;

	quickSort(nums, left, i-1);
	quickSort(nums, i+1,right);

}

int main(int argc, char **argv) {

	vector<int> nums {3,2,1,19,10,20,23,34,2,23,12,9,8,17};
	quickSort(nums,0, nums.size()-1);
	for(int i:nums) {
		cout<<i<<" ";
	}
   	cout<<endl;
	return 0;
}