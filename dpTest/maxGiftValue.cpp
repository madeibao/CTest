


// 剑指 Offer 47. 礼物的最大价值

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
   int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            dp[i][0]  = dp[i-1][0]+grid[i][0];
        }
        for (int i = 1; i < n; i++)
        {
            dp[0][i]  = dp[0][i-1]+grid[0][i];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, char**argv) {

	vector<vector<int>> nums = {{1,3,1},{1,5,1},{4,2,1}};
	Solution s2;
	cout<<s2.maxValue(nums)<<endl;
	return 0;
}
