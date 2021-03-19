

// 数组中的最小的k 个数字。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> lower(vector<int>&nums, int k) {

		vector<int> res(k, 0);
		if(k==0) return  res;
		priority_queue<int> queue;
		for(int i=0; i<k; ++i) {
			queue.push(nums[i]);
		}

		// 从k开始逐渐的添加进去。
		for(int i=k; i<(int)nums.size(); ++i)  {
			if(nums[i]<queue.top()) {
				queue.pop();
				queue.push(nums[i]);
			}
		}

		for(int i=0; i<k;i++) {
			res[i] = queue.top();
			queue.pop();
		}

		return res;
	}

};


int main(int argc, char** argv) {


	vector<int> temp {1,2,2,3,4,5,7};
	int k(2);
	vector<int> res;
	Solution s;
	res = s.lower(temp, k);
	for(int i=0; i<res.size();i++) {
        cout<<res[i]<<" ";

	}
	return 0;
}
