
// 调整奇数字和偶数字的位置。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
	vector<int> move(vector<int>& nums) {

		vector<int> res;
		if(nums.size()==0) return res;
		int i=0,j = nums.size()-1;
		
		while(i<=j) {
			if(nums[i]%2==1) {
				i++;
				continue;
			}

			if(nums[j]%2==0) {
				j--;
				continue;
			}
			swap(nums[i], nums[j]);
			i++;
			j--;
		}

		return nums;
	}
};
int main(int argc, char** argv) {
	vector<int> nums {1,2,3,4};
	Solution s;
	vector<int> res;
	res = s.move(nums);
	for(int i:res) {
		cout<<i<<" ";
	}

	return 0;
}
