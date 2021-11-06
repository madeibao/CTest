

/**
 两个单词之间的距离。
*/

#include "iostream"
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {

    	// 第一个单词和第二个单词的大小。
        int n = word1.size(), m = word2.size();
        // 一共是n+1行，m+1列。
        vector<vector<int> > dp(n+1, vector<int>(m+1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 0; i < m; ++i) dp[0][i+1] = i + 1;
        for (int i = 0; i < n; ++i) dp[i+1][0] = i + 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = dp[i][j];
                    continue;
                }
                // 插入
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]+1);
                // 删除
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1]+1);
                // 替换
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+1);
            }
        }
        return dp[n][m];
    }
};

int main(int argc, char** argv) {

	string stra = "horse";
	string strb = "ros";
	Solution s; 
	cout<<s.minDistance(stra,strb)<<endl;
	return 0;
}


