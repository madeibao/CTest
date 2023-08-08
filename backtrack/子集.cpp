




#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {

private:
	vector<vector<int> > result;
	vector<int> path;
	void backtracking(vector<int>& nums, int startIndex) {
		result.push_back(path);
		if(startIndex>=nums.size()) {
			return;
		}

		for(int i=startIndex; i<nums.size(); i++) {
			path.push_back(nums[i]);
			backtracking(nums, i+1);
			path.pop_back();
		}

	}
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }

};

int main(int argc, char** argv) {

	vector<int> nums = {1,2,3};
	vector<vector<int>> res;
	Solution s;
	res = s.subsets(nums);

    for(vector<int> a:res) {
        for(int i:a) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

	return 0;
}
