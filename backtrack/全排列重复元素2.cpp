
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<int> > result;
	vector<int> path;
	void backtracking(vector<int> &nums, vector<bool> &used) {
		if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++) {
			if(used[i]) {
				continue;
			}

        	if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false) {
        		continue;
        	}

        	if(used[i]==false) {
				used[i] = true;
	        	path.push_back(nums[i]);
	        	backtracking(nums,used);
	        	path.pop_back();
	        	used[i] = false;
        	}
        }
	}

    vector<vector<int>> permuteUnique(vector<int>& nums) {

    	result.clear();
    	path.clear();
		sort(nums.begin(),nums.end());
    	vector<bool> used(nums.size(),false);
		backtracking(nums,used);
      	return result;
    }
};

int main(int argc, char** argv) {

	vector<int> nums = {1,1,3};
	vector<vector<int>> res;
	Solution s;
	res = s.permuteUnique(nums);

    for(vector<int> a:res) {
        for(int i:a) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

	return 0;
}
