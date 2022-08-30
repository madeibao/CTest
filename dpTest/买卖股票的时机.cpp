
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size()==1) {
            return 0;
        }
    	int profit= INT_MIN;
    	int temp = prices[0];

    	for(int i=1;i<prices.size();i++) {
    		temp = min(temp, prices[i]);
    		profit = max(profit, prices[i]-temp);
    	}
    	return profit;
    }
};


int main(int argc, char* argv[]) {
	vector<int> prices ={7,1,5,3,6,4};
	Solution s;
	cout<<s.maxProfit(prices)<<endl;
	return 0;
}