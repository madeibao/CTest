
//--------------------------------------------------------------------
// -----------------------------------------------------------------------
// 插入排序


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

void sort(vector<int>& nums) {
	if(nums.size()==0) return;

	for(int i=1;i<nums.size();i++) {
		if(nums[i]<nums[i-1]) {
			int temp = nums[i];
			int j = i;
			while(j>0&&nums[j-1]>temp) {
				nums[j] = nums[j-1];
				j--;
			}
			nums[j] = temp;
		}
	}
}

int main(int argc,char** argv) {
	vector<int> nums {2,3,2,12,19,23};
	sort(nums);
	for(int i:nums) {
		cout<<i<<" "<<endl;
	}
    return 0;
}
