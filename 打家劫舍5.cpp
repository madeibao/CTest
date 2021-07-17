

// 打家劫舍算法
// 动态规划算法。

#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

class Solution {
public:
	int rob(vector<int>& arrs) {
		if(arrs.size()==0) {
			return 0;
		}
		if(arrs.size()==1) {
			return arrs[0];
		}
		if(arrs.size()==2) {
			return max(arrs[0], arrs[1]);
		}

		vector<int> dp(arrs.size(),0);
		dp[0] = arrs[0];
		dp[1] = max(arrs[1],arrs[0]);

		for(int i=2;i<arrs.size();i++) {
			dp[i] = max(dp[i-2]+arrs[i], dp[i-1]);
		}
		return dp[arrs.size()-1];
	}
};


int main(int argc, char* argv[]) {	

	vector<int> nums {1,2,3,1};
	Solution s; 
	cout<<s.rob(nums)<<endl;
	return 0;
}