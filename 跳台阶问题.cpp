
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int n) {

        if(n <= 1) return 1;
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i < n+1; i++) {
            dp[i] = (dp[i-1] + dp[i-2])%1000000007;
        }

        return dp[n];
    }
};

int main(int argc, char* argv[])  {

    Solution s;
    cout<<s.numWays(5)<<endl;
    return 0;
}





