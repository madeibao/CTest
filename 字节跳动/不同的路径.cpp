
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     *
     * @param m int整型
     * @param n int整型
     * @return int整型
     */
    int uniquePaths(int m, int n) {
        // write code here
        
        if(m==0||n==0) {
            return 1;
        }
        vector<vector<int>> dp(m, vector<int>(n,1));
        for(int i=1;i<m;i++) {
            for(int j=1;j<n;j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];

    }
};


int main(int argc, char** argv) {


    Solution s;

    int m = 2, n =1;
    cout<<s.uniquePaths(m,n)<<endl;
    return 0;
}
