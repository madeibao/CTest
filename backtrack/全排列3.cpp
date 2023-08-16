
//----------------------------------------------------------------
/**	
	这里是重复的元素来进行排列

*/

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	vector<vector<int> > res;
	vector<int> temp;
	vector<bool> visited;
	int len;
	vector<vector<int> > permutation(vector<int>& nums) {

		len = nums.size();
		visited.resize(len);
		sort(nums.begin(),nums.end());
		dfs(nums,0);
		return res;
	}

	void dfs(vector<int>& nums, int start) {
		if(start==len) {
			res.push_back(temp);
			return;
		}

		for(int i=0;i<len;i++) {
			if(visited[i]||(i>0&&nums[i]==nums[i-1]&&!visited[i-1])) {
				continue;
			}
			visited[i] = true;
			temp.push_back(nums[i]);
			dfs(nums,start+1);
			temp.pop_back();
			visited[i] = false;
		}
	}
};

int main(int argc, char** argv) {

	vector<int> nums = {1,1,3};
	vector<vector<int>> res;
	Solution s;
	res = s.permutation(nums);

    for(vector<int> a:res) {
        for(int i:a) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

	return 0;
}
