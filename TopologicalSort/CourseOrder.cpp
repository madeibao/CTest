
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> graph(numCourses);
        
        for(auto edge : prerequisites){
            int i = edge[0];
            int j = edge[1];
            graph[i].push_back(j);
            inDegree[j]++;
        }

        queue<int> q;
        int sum = 0;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            sum++;
            for(int i = 0; i < graph[top].size(); i++){
                int node = graph[top][i];
                inDegree[node]--;
                if(inDegree[node] == 0){
                    q.push(node);
                }
            }
        }
        return sum == numCourses;
    }
};


int main(){

	int numCourses = 2;
	vector<vector<int> > prerequisites = {{1,0}};
	Solution s2;
	
	return 0;
}