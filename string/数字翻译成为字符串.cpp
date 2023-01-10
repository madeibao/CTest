

// // 将数字翻译成字符串内容。
// 示例 1:

// 输入: 12258
// 输出: 5
// 解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        if(num < 10) {return 1;}

        string s = to_string(num);
        int len = s.length();
        vector<int> dp(len + 1);
        dp[1] = 1; // 显而易见 dp[1] = 1
        dp[0] = 1; // 比如 num = 12，有两种方法，即 dp[2] = dp[1] + dp[0]，可得 dp[0] = 1

        for(int i = 2; i < len + 1; ++i) {
            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '5')) {
                dp[i] = dp[i - 2] + dp[i - 1];
            }
            else {
                dp[i] = dp[i - 1];
            }
        }

        return dp[len];
    }
};


int main(int argc, char **argv) {

    int num = 12258;
    Solution s;
    cout<<s.translateNum(num)<<endl;

    return 0;
}
