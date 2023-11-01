


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int res =0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    res++;
                    res = max(res,dfs(grid,i,j));
                }
            }
        }

        return res;
    }

    int dfs(vector<vector<int>> & grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if(!(i>=0&&i<m&&j>=0&&j<n&&grid[i][j]==1)) {
            return 0;
        }
        if(grid[i][j]!=1) {
            return 0;
        }

        grid[i][j]= 2;
        return 1+dfs(grid,i+1,j)
                +dfs(grid,i-1,j)
                +dfs(grid,i,j+1)
                +dfs(grid,i,j-1);

    }
};

