
#include<iostream>
#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracing(vector<int>& candidates,int target,int sum,int startIndex){
        if(sum==target){
            res.push_back(path);
            return;
        }
        else if(sum>target){
            return;
        }

        for(int i=startIndex;i<candidates.size();i++){
            if(i>startIndex&&candidates[i]==candidates[i-1]) continue;
            path.push_back(candidates[i]);
            sum+=candidates[i];
            backtracing(candidates,target,sum,i+1);
            sum-=candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracing(candidates,target,0,0);
        return res;
    }
};


int main(){

    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution s2;
    vector<vector<int>> res;
    res = s2.combinationSum2(candidates, target);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
