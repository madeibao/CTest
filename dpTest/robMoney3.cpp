


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>f(n + 1);
        f[1] = nums[0];  //初始化
        for(int i = 2; i <= n; i++){
            f[i] = max(f[i-1], f[i - 2] + nums[i - 1]); //状态转移方程
        }
        return f[n];
    }
};

int main(int argc, char**argv) {

	vector<int> nums = {1,2,3,1};
	Solution s;
	cout << s.rob(nums) << endl;
	return 0;
}
