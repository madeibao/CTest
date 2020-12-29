
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int rob(vector<int>& res) {
        if(res.size()==0) {
            return 0;
        }
        if(res.size()==1) {
            return res[0];
        }
        if(res.size()==2) {
            return max(res.at(0), res.at(1));
        }
        vector<int> dp (res.size(),0);
        dp[0] = res[0];
        dp[1] = max(res[0], res[1]);
        for(unsigned int i=2;i<res.size();i++) {
            dp[i] = max(dp[i-2]+res[i],dp[i-1]);
        }
        return dp[res.size()-1];
    }
};

int main() {
    vector<int> temp  {1,2,3,1};
    Solution s;
    cout<<s.rob(temp);
    return 0;
}
