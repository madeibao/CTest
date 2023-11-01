

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
 	vector<vector<int> > res;
	vector<vector<int> > subSets(vector<int> nums) {

		if(nums.size() == 0) {
			return res;
		}
		vector<int> track;
		helper(nums, 0, track);
		return res;
	}

	void helper(vector<int > nums, int start, vector<int> track) {
		res.push_back(track);

		for(int i= start; i< nums.size(); i++) {
			track.push_back(nums[i]);
			helper(nums, i+1,track);
			track.pop_back();
		}
	}
};

int main(int argc, char** argv) {

	vector<int> nums {1,2,3};
	vector<vector<int>> res;

	Solution s;
	res = s.subSets(nums);
	for(auto i:res) {
		for(auto j:i) {
			cout << j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
