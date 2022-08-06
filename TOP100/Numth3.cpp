

// leetcode414
// 给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。

// 示例 1：

// 输入：[3, 2, 1]
// 输出：1
// 解释：第三大的数是 1 。

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      ordered_set<int> s;
      for(int i:nums) {
      	s.insert(i);
      }

      int n = s.size();

      if(n<3) {
      	return *(s.find_by_order(n-1));
      }
      else {
      	return *(s.find_by_order(n-3));
      }
    }
};

int main(int argc, char** argv) {

	vector<int> nums {2,1};
	Solution s;
	cout<<s.thirdMax(nums)<<endl;
	return 0;
}


