

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<int> multiply(vector<int>& nums) {

			// 如果是空的数组值。
			if(nums.size()==0) {
				return vector<int>();
			}

			vector<int> left(nums.size(), 1);
			vector<int> right(nums.size(),1);
			vector<int> result(nums.size(),1);
			for(int i=1;i<nums.size();i++) {
				left[i] = left[i-1]*nums[i-1];
			}

			for(int j= nums.size()-2;j>=0;j--) {
				right[j] = right[j+1]*nums[j+1];
			}

			for(int k=0;k<nums.size();k++) {
                result[k] = left[k]*right[k];
			}

			return result;
		}
};


int main(int argc, char* argv[]) {

	vector<int> res = {1,2,3,4,5};
	vector<int> res2;
	Solution s;
	res2 = s.multiply(res);
	for(int i=0;i<res2.size();i++) {
		cout<<res2[i]<<" ";
	}
	return 0;
}
