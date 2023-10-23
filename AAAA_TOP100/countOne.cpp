


// 221. 最大正方形



#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0,n=matrix.size(),m=matrix[0].size();
        int dp[n+10][m+10];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j]=='1')
                {
                    dp[i+1][j+1]=min(dp[i][j],min(dp[i][j+1],dp[i+1][j]))+1;
                    //这里ij都加一是为了防止后面-1不会小于零导致数组越界
                    ans=max(ans,dp[i+1][j+1]);
                }
        return ans*ans;
    }
};



int main(int argc, char** argv) {


    vector<vector<char> > matrix =       {{'1','0','1','0','0'},
                                          {'1','0','1','1','1'},
                                          {'1','1','1','1','1'},
                                          {'1','0','0','1','0'},};

    Solution s2;
    cout << s2.maximalSquare(matrix)<<endl;

    return 0;
}
