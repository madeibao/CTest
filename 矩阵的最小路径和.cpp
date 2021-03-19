
// 矩阵的最小路径和。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int>>& matrix) {
        // write code here
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0){
                    dp[i][j] = matrix[i][j];
                }
                else if(i == 0) {
                    dp[i][j] = dp[i][j-1] + matrix[i][j];
                }
                else if(j == 0) {
                    dp[i][j] = dp[i-1][j] + matrix[i][j];
                }
                else {
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        return dp[n-1][m-1];
    }
};


int main() {

    vector<vector<int>> matrix = {{1,3,5,9},{8,1,3,4},{5,0,6,1},{8,8,4,0}};
    Solution s;
    cout<<s.minPathSum(matrix);
    return 0;
}










