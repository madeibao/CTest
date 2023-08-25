


/**

	DFS 的写法， 
	首先实现四个方向
**/



#include<iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    int numIslands(vector<vector<char>>& grid) {
 		int i, j, m = grid.size(), n = grid[0].size(), cnt = 0;
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					dfs(grid, i, j);
					cnt++;
				}
			}
		}
		return cnt;
    }

    void dfs(vector<vector<char>> & grid, int i, int j) {

        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!='1') {
            return;
        }
        grid[i][j]='2';
        for(int index = 0;index < 4;index++) {
            dfs(grid,i+x[index],j+y[index]);
        }
    }
};


int main(int argc, char **argv) {

	vector<vector<char>> grid = {{'1','1','0','0','0'},
								 {'0','1','0','1','1'},
								 {'0','0','0','1','1'},
								 {'0','0','0','0','0'},
							     {'0','0','1','1','1'},
								};
	Solution s;
	cout<<s.numIslands(grid)<<endl;
	return 0;
}
