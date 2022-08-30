
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	void sortA(vector<int>& nums) {
		int flag = 0;
		for (int i = 0; i < nums.size();i++) {
			for(int j=0;j<nums.size()-1-i;j++) {
				if(nums[j]>nums[j+1]) {
					swap(nums[j],nums[j + 1]);
					// 如果有交换，就加入标志位
					flag=1;
				}
			}

			// 如果没有交换元素，表示已经有序
			if(flag==0) {
				return;
			}
		}
	}

};

int main(int argc,char** argv) {
	vector<int> nums {2,3,2,12,19,23};
	Solution s2;
	s2.sortA(nums);
	for(int i:nums) {
		cout<<i<<" "<<endl;
	}
    return 0;
}