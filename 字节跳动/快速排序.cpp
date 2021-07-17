
#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

int helper(vector<int> &nums, int low, int high) {
	int temp = nums[low];

	while(low<high) {

		while (low<high&&nums[high]>temp) {
			high--;
		}

		while (low<high&&nums[low]<temp) {
			low++;
		}

		if(low<high) {
			int t = nums[low];
			nums[low] = nums[high];
			nums[high] = t;
		}
	}

	nums[low] = temp;
	return low;
}

void quick(vector<int> &nums, int left, int right) {
	if(left<right) {
		int middle = helper(nums, left, right);
		quick(nums, left ,middle-1);
		quick(nums,middle+1, right);
	}
}

int main(int argc, char* argv[]) {

	vector<int> res {2,3,1,4,5};
	quick(res, 0, res.size()-1);
	for(int i:res) {
		cout<<i<<" ";
	}
	return 0;
}
