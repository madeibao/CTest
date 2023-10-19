

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	  vector<vector<int> > res;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0,nums.size());
        return res;
   	}

   	void dfs(vector<int>& nums, int left, int right) {
   		if(left == right) {
   			res.push_back(nums);
   			return;
   		}

   		for(int i= left; i< nums.size(); i++) {
   			swap(nums[left], nums[i]);
   			dfs(nums,left+1, right);
   			swap(nums[left], nums[i]);
   		}
   	}
};


int main(int argc, char** argv) {

	vector<int> nums = {1,2,3};
	vector<vector<int>> res;
	Solution s;
	res = s.permute(nums);

    for(vector<int> a:res) {
        for(int i:a) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

	return 0;
}
