
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int s_len = s.length();
        vector<int> dp(s_len + 1, 0);

        dp[0] = 1;

        for(int i=1;i<=s.size();i++) {
            if (s[i - 1] != '0') dp[i] = dp[i - 1];
            if (i - 1 > 0 && ((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6'))) {
                //状态转移公式
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.size()];

    }
};

int main() {

    Solution s2;
    string s = "12";
    cout<<s2.numDecodings(s)<<endl;
    return 0;
}