

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>>
     * @return int整型
     */
    int solve(vector<vector<char>>  &grid) {
        // write code here
        int res = 0;
        if (grid.size() == 0) return res;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, unsigned int i, unsigned int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};

int main(int argc, char*argv[]) {

    vector<vector<char>> num = {{'1','1','0','0','0'},
                                {'0','1','0','1','1'},
                                {'0','0','0','1','1'},
                                {'0','0','0','0','0'},
                                {'0','0','1','1','1'}};

    Solution s;
    cout<<s.solve(num);
    return 0;
}




