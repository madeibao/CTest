


#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	vector<int> res;

    	unordered_map<int, int> m;

    	for(int i:nums) {
    		m[i]++;
    	}

    	priority_queue<pair<int, int>> queue2;

    	for(auto i:m) {
    		queue2.emplace(i.second,i.first);
    	}

    	for(int i=0;i<k;i++) {
    		res.push_back(queue2.top().second);
    		queue2.pop();
    	}
    	return res;
    }
};


int main(int argc, char** argv) {


	vector<int> nums = {1,1,1,2,2,3};
	int k = 2;
	Solution s;
	vector<int> res;
	res =s.topKFrequent(nums,k);
	for(int i:res) {
		cout << i<<" "<<endl;
	}
	return 0;
}
