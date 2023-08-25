

#include<iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int add = 4;    //方格初始周长
                if(grid[i][j] == 1) {
                    if(i -1 >= 0 && grid[i -1][j] == 1) add--;  //上
                    if(i +1 < m && grid[i +1][j] == 1) add--;   //下
                    if(j -1 >= 0 && grid[i][j -1] == 1) add--;  //左
                    if(j +1 < n && grid[i][j +1] == 1) add--;   //右
                    res += add;
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

    vector<vector<int> > grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    Solution s2;
    cout<<s2.islandPerimeter(grid)<<endl;
	return 0;
}


