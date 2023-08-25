



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	int m_x[4] = {0, 0, -1, 1};
    int m_y[4] = {1, -1, 0, 0};

    int numIslands(vector<vector<char>>& grid) {
 		int i, j, m = grid.size(), n = grid[0].size(), cnt = 0;
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					bfs(grid, i, j, m, n);
					cnt++;
				}
			}
		}
		return cnt;
    }

	void bfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
		queue<pair<int,int>> queue2;
		queue2.push({x,y});

		grid[x][y] = '0';

		while(!queue2.empty()) {
			int nx = queue2.front().first;
			int ny = queue2.front().second;

			// 弹出这个元素
			queue2.pop();

			for(int i=0;i<4;i++) {
				x = nx+m_x[i];
				y = ny+m_y[i];
				if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]=='1') {
					queue2.push({x,y});
					grid[x][y] = '0';
				}
			}
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
