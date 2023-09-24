
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    void isEnclaves(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        for (int index = 0; index < 4; ++index) {
            int next_i = i + di[index];
            int next_j = j + dj[index];
            isEnclaves(grid, next_i, next_j);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0;

        // 首先把最上面和最下面淹没
        for (int j = 0; j < grid[0].size(); ++j) {
            isEnclaves(grid, 0, j);
            isEnclaves(grid, grid.size() -1 , j);
        }

        // 最左面和最右面淹没
        for (int i = 0; i < grid.size(); ++i) {
            isEnclaves(grid, i, 0);
            isEnclaves(grid, i, grid[0].size() - 1);
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (1 == grid[i][j]) {
                    result++;
                }
            }
        }

        return result;
    }
};

int main(int argc, char** argv) {

	vector<vector<int>> grid = {{0,0,0,0},
                                {1,0,1,0},
                                {0,1,1,0},
                                {0,0,0,0}};
	Solution s2;
	cout<<s2.numEnclaves(grid)<<endl;

	return 0;
}
