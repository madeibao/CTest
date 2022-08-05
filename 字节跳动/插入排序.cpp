

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	void insertSort(vector<int>& nums) {
		int temp,j;
		for(int i=1;i<nums.size();i++) {
			int temp = nums[i];
			int j = i-1;
			while(j>=0&&nums[j]>temp) {
				nums[j+1] = nums[j];
				j--;
			}

			nums[j+1] = temp;
		}
	}
};

int main(int argc, char** argv) {

	vector<int> nums {3,2,1,3,8,7,12,13,7};
	Solution s;
	s.insertSort(nums);
	for(int i:nums) {
		cout << " " << i << endl;
	}
	return 0;
}