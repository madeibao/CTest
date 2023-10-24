



#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());   //排序
        int ans = 0;
        for(int i = 0; i < n; i += 2){ //选择每对中更小的那个
            ans += nums[i];
        }
        return ans;
    }
};



int main() {

	vector<int> nums {1,3,4,2};
	Solution solution;
	cout<<solution.arrayPairSum(nums)<<endl;
	return 0;
}
