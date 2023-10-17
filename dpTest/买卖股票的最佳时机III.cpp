

// 这里最多买入和卖出两次

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;

        for(auto &p: prices) {

            firstBuy = max(firstBuy,-p);
            firstSell = max(firstSell, firstBuy+p);

            secondBuy = max(secondBuy,firstSell - p);
            secondSell = max(secondSell,secondBuy + p);
        }

        return secondSell;
    }
};

int main(){
    vector<int> nums = {3,3,5,0,0,3,1,4};
    Solution s;
    cout<<s.maxProfit(nums);
    return 0;
}




