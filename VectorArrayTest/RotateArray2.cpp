// 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
// 如果向左

// 示例 1:


// 向左旋转
// 输入: nums = [1,2,3,4,5,6,7], k = 3
// 4 5 6 7 1 2 3 


// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/rotate-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出
#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = (int) nums.size();
        k = k % len;

		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


int main() {

	vector<int> nums {1, 2, 3, 4, 5, 6, 7,};
	int k(3);
	Solution s2;
	s2.rotate(nums, k);
	for(auto i:nums) {
		cout <<i<<" "<<endl;
	}


	return 0;
}
