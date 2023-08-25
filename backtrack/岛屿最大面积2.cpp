

#include<iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int getArea(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        int result = 1;
        grid[i][j] = 0;
        int test1[4] = {-1,0,1,0};
        int test2[4] = {0,1,0,-1};
        for (int index = 0; index < 4; ++index) {
            int next_i = i + test1[index];
            int next_j = j + test2[index];
            result += getArea(grid, next_i,next_j);
        }
        return result;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                max = std::max(max, getArea(grid, i, j));
            }
        }
        return max;
    }

};


int main(int argc, char** argv) {

	vector<vector<int> > grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
								 {0,0,0,0,0,0,0,1,1,1,0,0,0},
								 {0,1,1,0,1,0,0,0,0,0,0,0,0},
								 {0,1,0,0,1,1,0,0,1,0,1,0,0},
								 {0,1,0,0,1,1,0,0,1,1,1,0,0},
								 {0,0,0,0,0,0,0,0,0,0,1,0,0},
								 {0,0,0,0,0,0,0,1,1,1,0,0,0},
								 {0,0,0,0,0,0,0,1,1,0,0,0,0}};

	Solution s2;
	cout<<s2.maxAreaOfIsland(grid)<<endl;
	return 0;
}
