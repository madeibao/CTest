
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> &prices) {
        int res =0;
        int buy =INT_MAX;
        for(int price:prices) {
            buy = min(buy, price);
            res = max(res, price-buy);
        }
        return res;
    }
};


int main(){
    vector<int> nums = {7,1,5,3,6,4};
    Solution s;
    cout<<s.maxProfit(nums);
    return 0;
}




