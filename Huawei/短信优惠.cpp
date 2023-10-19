


#include <bits/stdc++.h>
using namespace std;

int main() {
	int sum;
	cin >> sum;
	int tmp;
	vector<int>num;//存放每种套餐对应的短信数
	vector<int>dp(sum+1,0);
	while (cin >> tmp) {
		num.push_back(tmp);
		if (cin.get() == '\n')
			break;
	}
	for (int i = 0; i < num.size(); i++) {
		for (int j = i+1; j <= sum; j++) {
			dp[j]=max(dp[j],dp[j-i-1]+num[i]);//j-(i+1)->i号套餐对应的费用为i+1
		}
	}
	cout << dp[sum];
}
