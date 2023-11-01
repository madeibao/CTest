


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &nums, vector<bool> & visited) {

        if(path.size()==nums.size()) {
            res.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(visited[i]) {
                continue;
            }

            if(i>0&&nums[i]==nums[i-1]&&visited[i-1]==false) {
                continue;
            }

            if(visited[i]==false) {
                visited[i] = true;
                path.push_back(nums[i]);
                dfs(nums,visited);
                path.pop_back();
                visited[i] = false;

            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        res.clear();
        path.clear();
        sort(nums.begin(),nums.end());
        vector<bool> visited(nums.size(),false);
        dfs(nums, visited);
        return res;
    }

};

int main() {

    vector<int> nums {1,1,3};
    vector<vector<int>> res;
    Solution s2;
    res = s2.permute(nums);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
