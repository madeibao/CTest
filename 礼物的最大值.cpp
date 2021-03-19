

// 礼物的最大值，形式。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=1;i<=m;i++)
        	for(int j=1;j<=n;j++)
        		dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];

        return dp[m][n];
    }
};


int main(int argc, char* argv[]) {

	vector<vector<int>> res ={{1,3,1},{1,5,1},{4,2,1}};
	Solution s;
	cout<<s.maxValue(res)<<endl;
	return 0;
}
