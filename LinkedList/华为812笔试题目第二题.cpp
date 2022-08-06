

/**
2
3 5
1 0 1 0 0
0 1 1 0 1
0 0 1 0 1
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& nums, int s, int i, int j) {
    if(i<0||j<0||i>=nums.size()||j>=nums[0].size()||nums[i][j]==0) {
        return false;
    }
    if(i==nums.size()-1||j==nums[0].size()-1) {
        return true;
    }
    nums[i][j]=0;
    return dfs(nums, s, i-s,j)||dfs(nums,s, i+s,j)||dfs(nums, s, i,j-s)||dfs(nums,s, i,j+s);
}

int main(){
    int m, n, s;
    cin>>s;
    cin>>m>>n;
    vector<vector<int>> res(m, vector<int>(n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>res[i][j];
        }
    }

    if(dfs(res, s, 0,0)) {
        cout<<"true";
    }
    else  {
        cout<<"false";
    }
    return 0;

}

