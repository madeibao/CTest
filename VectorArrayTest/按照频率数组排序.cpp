

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
		unordered_map<int, int> hash;//hash计数

		for (int i = 0; i < nums.size(); i++) {
			hash[nums[i]]++;
		}

    	vector<int> res;
    	vector<pair<int, int>> arr;

		for(auto it : hash) {
		  arr.emplace_back(it);
		}
		// 重写compare函数，如果value值相同，则按照key值排序
        sort(arr.begin(), arr.end(), [](auto p1, auto p2) {
             return p1.second == p2.second ? p1.first > p2.first : p1.second < p2.second;
        });

		for(auto it: arr) {
		  for(int i=0;i<it.second;i++) {
            res.push_back(it.first);
		  }
		}
    	return res;
    }
};

int main() {

	vector<int> nums  {1,1,2,2,2,3};
	Solution s2;
	vector<int> res;
	res = s2.frequencySort(nums);
	for(auto i:res) {
		cout<<i<<" ";
	}
    return 0;
}
