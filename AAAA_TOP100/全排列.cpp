
#include "iostream"
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int n;
    vector<vector<int>> r;
    void DFS(vector<int>& a, int s){
        if(s == n){ // 所有位置都交换过
            r.emplace_back(a);
            return;
        }
        for(int i=s;i<n;i++){
            swap(a[i], a[s]); // 交换位置i和s对应元素
            DFS(a, s+1); // 深搜起始交换位置+1
            swap(a[i], a[s]); // 回溯，交换位置i和s对应元素
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        DFS(nums, 0); // 从起始交换位置0开始深搜
        return r;
    }
};


int main(int argc, char** argv) {

	vector<vector<int>> res;
	Solution s;
	vector<int> nums {1,2,3};
	res = s.permute(nums);
	for(auto i:res) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}