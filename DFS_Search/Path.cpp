

// 深度优先遍历


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void process(vector<vector<int>>& graph,int cur,vector<int>tmp,int target){
        tmp.push_back(cur);
        if(cur == target){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<graph[cur].size();i++){
            process(graph,graph[cur][i],tmp,target);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        process(graph,0,vector<int>(),graph.size()-1);
        return ans;
    }
};

int main() {

    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    Solution s2;
    vector<vector<int>> res;
    res = s2.allPathsSourceTarget(graph);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}