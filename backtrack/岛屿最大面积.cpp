

#include<iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<char>>& grid) {
	    if (grid.empty() || grid[0].empty()) {
	        return 0;
	    }

	    int res = 0;
	    for (int r = 0; r < grid.size(); r++) {
	        for (int c = 0; c < grid[0].size(); c++) {
	            if (grid[r][c] == '1') {
	                int a = area(grid, r, c);
	                res = max(res, a);
	            }
	        }
	    }
	    return res;
	}

	int area(vector<vector<char>>& grid, int r, int c) {
	    if (!(0 <= r && r < grid.size()
	          && 0 <= c && c < grid[0].size())) {
	        return 0;
	    }
	    if (grid[r][c] != '1') {
	        return 0;
	    }
	    grid[r][c] = '2';
	    return 1
	        + area(grid, r - 1, c)
	        + area(grid, r + 1, c)
	        + area(grid, r, c - 1)
	        + area(grid, r, c + 1);
	}

};
int main(int argc, char const *argv[])
{

	vector<vector<char> > grid = {{'0', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0'},
								  {'0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0'},
								  {'0', '1', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0'},
								  {'0', '1', '0', '0', '1', '1', '0', '0', '1', '0', '1', '0', '0'},
								  {'0', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '0', '0'},
								  {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0'},
								  {'0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0'},
								  {'0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0'}};

	Solution w2;

	cout<<w2.maxAreaOfIsland(grid)<<endl;
	return 0;
}
