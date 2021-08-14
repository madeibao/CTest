

// 股票买卖交易两次算法。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        int mn=INT_MAX,ans=0;
        for(int i=0;i<(int)prices.size();i++){
            mn=min(mn, prices[i]);
            ans=max(ans, prices[i]-mn);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {

	vector<int> res = {1,4,2};
	Solution s;
	cout<<s.maxProfit(res)<<endl;
	return 0;
}
