
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		vector<vector<int>> dp(nums.size(), vector<int>(10005, 0));
		//dp[i][j]表示在0-i个数据的集合中，往容量为j的背包，放价值最大的数据（数据的重量和价值都是数据本身的值）
		int sum = 0;
		for (auto num : nums) {
			sum += num;
		}

		if (sum % 2 != 0) {  //如果总和不能整除2，则必然无法分成两个总和相等的数据子集
			return false;
		}

		int target = sum / 2;
		for (int j = 0; j <= target; j++) {  //初始化行
			if (j >= nums[0]) {  //这里的nums[j]表示物品重量
				dp[0][j] = 0;  //这里的nums[j]表示物品价值
			}
		}

		for (int i = 0; i < nums.size(); i++) {  //初始化列
			dp[i][0] = 0;
		}

		for (int i = 1; i < nums.size(); i++) {
			for (int j = 1; j <= target; j++) {
				if (j < nums[i]) {  //如果j < nums[i]，表示当前背包放不下i这个数据
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
				}
			}
		}
		return dp[nums.size() - 1][target] == target;  //如果相等，表示在大小为j的背包
		//中，可以放下的数据子集的最大总和为j（这个最大总和肯定是<=j的，
		//因为数据的重量和价值是相等的），也就是找到了一个总和为j的子集
	}
};


int main(int argc, char** argv) {

	vector<int> nums {1,5,11,5};
	Solution s2;
	cout<<s2.canPartition(nums)<<endl;
	return 0;
}
