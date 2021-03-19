

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
	vector<int> minNum(vector<int>& nums, int k) {

		vector<int> res;
		if(nums.size()==0) {
			return res;
		}

		priority_queue<int> queue;
		for(int i=0; i<k; i++) {
			queue.push(nums[i]);
		}

		for(int i=k;i<(int)nums.size();i++) {
			if(nums[i]<queue.top()) {
				queue.pop();
				queue.push(nums[i]);
			}
		}


		for(int i=0;i<k;i++) {
			res[i] = queue.top();
			queue.pop();
		}
		return res;
	}
};


int main(int argc, char* argv[]) {


	vector<int> res {1,2,1,3,4,5,6,7,8,9,10};
	int k(2);
	vector<int> temp;
	Solution s; 

	temp = s.minNum(res, k);
	for(int i=0;i<temp.size();i++) {
		cout<<temp[i]<<" ";
	}

	return 0;
}