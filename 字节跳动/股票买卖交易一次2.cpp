
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// 动态规划的实现方法。
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int res =0;
            int temp = INT_MAX;
            for(int i=0;i<(int)prices.size();i++) {
                temp = min(prices[i], temp);
                res  = max(res, prices[i]-temp);
            }
            return res;
        }
};


int main(int argc, char **argv) {


    vector<int> prices  {1,4,2};
    Solution s;
    cout<<s.maxProfit(prices);

    return 0;
}
