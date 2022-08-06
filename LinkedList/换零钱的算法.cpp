
后来从dp下手做，参考了一下别人的做法，其实就是一个完全背包问题（以完全背包来做就不用担心组合重复的情况，因为只是考虑当前硬币选或不选）：

状态：硬币，金额

选择：当前硬币选或不选

dp数组含义：dp[i][j]表示前i个硬币可以达到j金额的组合数

方程：dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i-1]]dp[i][j]=dp[i−1][j]+dp[i][j−coins[i−1]]

（就是不选和选相加，注意选时的硬币下标仍为i，因为硬币个数无限，这个硬币上次仍然可以选----==也是完全背包和01背包的唯一不同之处==）

base case：dp[i][0] = 1, dp[0][j]=0,j\neq 0dp[i][0]=1,dp[0][j]=0,j=0（第二个可以不写，但我还是写了，反正是比较慢的做法，也不差这个，hh）



//--------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // dp数组含义：dp[i][j]表示前i个硬币可以达到j金额的组合数
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        //base case:

        // 第一列的值全部设置为1.
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }


        // 第一行的全部的设置为0.

        for(int i = 1; i <= amount; i++) {
            dp[0][i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) {
                if(j - coins[i - 1] >= 0) {
                	dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]; //完全背包，选的情况仍为i
                }
                else {
                	dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for(int x=0;x<=n;x++) {
            for(int y =0;y<=amount;y++) {
                cout<<dp[x][y]<<" ";
            }
            cout<<endl;
        }
        return dp[n][amount];
    }

};


int main(int argc, char* argv[]) {

	vector<int> res = {1,2,5};
	int amount = 5;
	Solution s;
	cout<<s.change(amount, res)<<endl;
	return 0;
}
