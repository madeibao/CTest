

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int dp[row][col];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < row; i++) {//初始化第一列
            dp[i][0] = dp[i - 1][0]  + grid[i][0];
        }
        for(int i = 1; i < col; i++) {//初始化第一行
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][col - 1];
    }
};

int main(int argc, char **argv) {

	vector<vector<int>> res {{1,3,1},{1,5,1},{4,2,1}};
	Solution solution;
	cout << solution.minPathSum(res) << endl;
	return 0;
}
