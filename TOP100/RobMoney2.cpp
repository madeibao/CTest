

#include<iostream>
#include<bits/stdc++.h>

usng namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.size()==0) {
			return 0;
		}

		if(nums.size()==1) {
			return num[0];
		}

		if(nums.size()==2) {
			return max(num[0], num[1]);
		}


		int a = num[0];
		int b = max(num[0], num[1]);
		int c = 0;

		for(int i=2;i<=nums.size();i++) {
			c = max(c, b+num[i]);
			a = b;
			b = c;
		}

		return c==0?a>b?a:b:c;
	}


};

int main(int argc, char** argv) {

	vector<int> nums = {1,2,3,1};
	Solution s2;
	cout<<s2.rob(nums)<<endl;

	return 0;
}