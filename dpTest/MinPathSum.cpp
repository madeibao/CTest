


class Solution {
    public:
        // 4. 动态规划：从终点到起始点
        int minPathSum2(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();

            // 状态定义：dp[i][j] 表示从坐标 (i, j) 到右下角的最小路径和
            vector<vector<int>> dp(m, vector<int>(n));

            // 状态初始化
            dp[m - 1][n - 1] = grid[m - 1][n - 1];

            // 状态转移
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j != n - 1) { // 最后一行
                        dp[i][j] = grid[i][j] + dp[i][j + 1];
                    } else if (i != m - 1 && j == n - 1) { // 最后一列
                        dp[i][j] = grid[i][j] + dp[i + 1][j];
                    } else if (i != m - 1 && j != n - 1) {
                        dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                    }
                }
            }

            // 返回结果
            return dp[0][0];
        }
};

