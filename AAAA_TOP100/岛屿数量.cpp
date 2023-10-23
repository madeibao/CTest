
// 这里是深度优先遍历算法

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>> &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                // 如果是岛屿，才以它为起点开始DFS，遍历后，1变为2，表示visited，防止重复遍历
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    // 判断是否仍然在网格之中
    bool inArea(vector<vector<char>>& grid, int i, int j) {
    	int m = grid.size();
    	int n = grid[0].size();

    	return i>=0&&i<m&&j>= 0&&j<n&&grid[i][j] =='1';
    }

	void dfs(vector<vector<char>> &grid, int x, int y)
    {
        // 主函数dfs前有一句判断，只有grid[x][y] == 1才会进入这个dfs
        grid[x][y] = '2'; // 标记visited
        if (inArea(grid, x - 1, y))
            dfs(grid, x - 1, y);
        if (inArea(grid, x + 1, y))
            dfs(grid, x + 1, y);
        if (inArea(grid, x, y - 1))
            dfs(grid, x, y - 1);
        if (inArea(grid, x, y + 1))
            dfs(grid, x, y + 1);
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
