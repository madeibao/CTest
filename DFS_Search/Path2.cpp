
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int> > ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> now_ans;
        n = graph.size();
        vector<int> vis(n,0);
        vis[0] = 1;
        now_ans.push_back(0);
        dfs(0,vis,now_ans,graph);
        return ans;
    }

    void dfs(int x,vector<int>& vis,vector<int>& now_ans,vector<vector<int>>& graph){
        if(x == n -1){
            ans.push_back(now_ans);
            return;
        }
        for(int i = 0; i < graph[x].size(); i++){
            int to = graph[x][i];
            if(vis[to] == 1) continue;//已经走过了
            vis[to] = 1;
            now_ans.push_back(to);
            dfs(to,vis,now_ans,graph);
            now_ans.pop_back();
            vis[to] = 0;  // 弹出
        }
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