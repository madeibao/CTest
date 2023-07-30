
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

    	// 首先初始化一个数组。
    	vector<vector<int>> dp (m, vector<int>(n,0));

    	for(int i = 0; i < m  && obstacleGrid[i][0]== 0;i++) {
    		dp[i][0] = 1;
    	}

    	for(int j=0; j<n&& obstacleGrid[0][j]==0;j++) {
    		dp[0][j] = 1;
    	}

    	for(int i=1;i<m;i++) {
    		for(int j=1;j<n;j++) {
    			if(obstacleGrid[i][j]==1) {
    				continue;
    			}
    			else {
    				dp[i][j] = dp[i-1][j]+dp[i][j-1];
    			}
    		}
    	}

    	return dp[m-1][n-1];
    }
};

int main(){

    vector<vector<int>> m {{0,0,0},{0,1,0},{0,0,0}};
    Solution s2;
    cout<<s2.uniquePathsWithObstacles(m);

    return 0;
}
