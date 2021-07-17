
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
	int rob(vector<int>& arr) {
		if(arr.size()==0) return 0;
		if(arr.size()==1) {
			return arr[0];
		}

		if(arr.size()==2) {
			return max(arr[0],arr[1]);
		}
		// 初始化一个数组，默认值为0
		vector<int> dp {arr.size(), 0};

		dp[0] = arr[0];
		dp[1] = max(arr[1],arr[0]);
		for(int i=2;i<arr.size();i++) {
			// 打劫前面两家，打劫本家，或者是打劫前面的一家。
			dp[i] = max(dp[i-2]+arr[i], dp[i-1]);
		}
		return dp[arr.size()-1];
	}
};

int main(int argc, char** argv) {

	vector<int> temp {1,2,3,1};
	Solution s;
	cout<<s.rob(temp)<<endl;
	return 0;
}
