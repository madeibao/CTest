#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        path.push_back(0);
        helper(graph,res,path,0,graph.size()-1);
        return res;
    }

    void helper(vector<vector<int>>&graph, vector<vector<int>>&res, vector<int>& path, int startIndex, int target) {

        if(startIndex==target) {
            res.push_back(path);
            return;
        }

        for(auto i:graph[startIndex]) {
            path.push_back(i);
            helper(graph, res,path,i,target);
            path.pop_back();
        }
    }
};

int main() {

    // vector<vector<int>> graph= [[1,2],[3],[3],[]]
    vector<vector<int>> graph = {{1,2},{3},{3},{}};

    Solution s2;
    vector<vector<int>> res;
    res = s2.allPathsSourceTarget(graph);
    for(auto i:res ) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
