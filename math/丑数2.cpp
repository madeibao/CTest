

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> dp(n+1);

        dp[1] = 1;

        int p2 = 1,p3 = 1,p5 = 1;

        for(int i=2;i<=n;i++) {
            int num2 = dp[p2]*2,num3= dp[p3]*3,num5 = dp[p5]*5;

            dp[i] = min(min(num2,num3),num5);

            if(num2==dp[i]) {
                p2++;
            }

            if(num3==dp[i]) {
                p3++;
            }
            
            if(num5==dp[i]) {
                p5++;
            }
        }

        return dp[n];
    }
};

int main() {

    Solution s2;
    int n = 10;
    cout<<s2.nthUglyNumber(n)<<endl;
    return 0;
}