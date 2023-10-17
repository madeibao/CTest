

// 这里的可以多次的买入和卖出股票

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {7,1,5,3,6,4};
    Solution s;
    cout<<s.maxProfit(nums);
    return 0;
}




