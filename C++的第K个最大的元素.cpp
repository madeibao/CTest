
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int res=0;
		int size = nums.size();

		if(size == 0||k>size) {
			return 0;
		}

		// 这里构建的是一个大顶堆。
		priority_queue<int, vector<int>, greater<int>> store;
		for(int i =0;i<size;i++) {
			store.push(nums[i]);
			if(int(store.size())>k) {
				store.pop();
			}
		}

		result = store.top();
		return result;
	}
};


int main(int argc, char *argv[]) {
	vector<int> nums= {3,2,1,5,6,4};
	int k =2;
	Solution s;
	cout<<s.findKthLargest(nums, k)<<endl;

	return 0;
}