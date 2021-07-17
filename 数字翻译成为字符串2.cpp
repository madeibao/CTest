
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int translateNum(int num) {
        if(num<10) {
            return 1;
        }

        string str = to_string(num);
        int len = str.length();
        vector<int> dp(len+1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<len+1;i++) {
            if(str[i-2] == '1'||(str[i-2]=='2'&&str[i-1] <='5')) {
                dp[i] = dp[i-2]+dp[i-1];
            }
            else {
                dp[i] = dp[i-1];
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
