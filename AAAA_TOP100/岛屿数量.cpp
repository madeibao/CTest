

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int res = 0;

        for(int i=0;i<m;i++) {
        	for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    res++;
                    dfs(grid,i,j);
                }
        	}
        }

        return res;
    }

    void dfs(vector<vector<char>>&grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
    	
    	if(i<0||i>=m||j<0||j>=n||grid[i][j]!='1') {
    		return;
    	}

    	grid[i][j] = '2';

    	dfs(grid, i+1,j);
    	dfs(grid, i-1,j);
    	dfs(grid, i,j+1);
    	dfs(grid, i,j-1);

    }
};