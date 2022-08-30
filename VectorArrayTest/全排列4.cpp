
#include "iostream"
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0, nums.size() - 1, nums);
        return result;
    }

private:
    vector<vector<int>> result;
    void dfs(int begin, int end, vector<int>& nums) {
        if (begin == end) {
            result.emplace_back(nums);
        }
        for (int i = begin; i <= end; i++) {
            swap(nums[i], nums[begin]);
            dfs(begin + 1, end, nums);
            swap(nums[i], nums[begin]);
        }
    }
};

int main(int argc, char*argv[]) {

	vector<int> nums {1,2,3};
	vector<vector<int>> res;

	Solution s;
	res = s.permute(nums);
	for(auto i:res) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}

	return 0;
}
