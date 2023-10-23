


// 有重复元素的子集合


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        sort(nums.begin(),nums.end());
        backtrack(nums,0,sub);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& sub){
        res.push_back(sub);
        for(int i=start;i<nums.size();i++){ //从start开始
            if(i>start && nums[i]==nums[i-1]) continue; // 如果下一个和上一个是同一个数
            sub.push_back(nums[i]);
            backtrack(nums,i+1,sub);
            sub.pop_back();
        }
    }
};

int main(int argc, char** argv) {

	vector<int> nums {1,2,2};
	vector<vector<int>> res;

	Solution s;
	res = s.subsetsWithDup(nums);
	for(auto i:res) {
		for(auto j:i) {
			cout << j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
