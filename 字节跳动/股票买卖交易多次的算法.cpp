
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int> &prices) {
        // write code here
        if (prices.size() <= 1)
            return 0;

        int mx = 0;
        for (unsigned int i = 1; i < prices.size(); i++)
            mx += max(prices[i] - prices[i - 1], 0);
        return mx;
    }
};


int main(int argc, char *argv[]) {


	vector<int> res {1, 2, 3, 4, 5, 6};

	Solution s;
	cout<<s.maxProfit(res);
	return 0;
}
