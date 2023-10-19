

#include "iostream"
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int cities, int i) {
		for(int j=0;j<cities;j++) {
			if(isConnected[i][j]==1&&!visited[j]) {
				visited[j] = 1;
				dfs(isConnected,visited,cities,j);
			}
		}
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
    	int cities = isConnected.size();

    	vector<int> visited(cities);
    	int province = 0;

    	for(int i=0;i<cities;i++) {
    		if(!visited[i]) {
    			dfs(isConnected, visited, cities,cities,i);
    			province++;
    		}
    	}
    	return province;
    }
};


int main(int argc, char** argv) {

	vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
	Solution s2;
	cout<<s2.findCircleNum(isConnected)<<endl;
	return 0;
}
