

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int res=0;

        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    res++;
                    // 深度递归遍历矩阵，最终遍历所有内容
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {

        int m = grid.size();
        int n = grid[0].size();
        if(x<0||x>m||y<0||y>m||grid[i][j]='0') {
        	return;
        }
        grid[i][j] = '0';

        dfs(grid, i-1,j);
        dfs(grid, i+1,j);
        dfs(grid, i,j-1);
        dfs(grid, i,j+1);

    }

};

int main(int argc, char** argv) {

	vector<vector<char>> res = {{'1','1','1','1','0'},
								{'1','1','0','1','0'},
								{'1','1','0','0','0'},
								{'0','0','0','0','0'},};
	Solution solution;
	cout << solution.numIslands(res)<<endl;
	return 0;

}
