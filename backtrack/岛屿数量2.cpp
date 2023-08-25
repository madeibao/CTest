

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
     	int res = 0;
       	for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]=='1'){
                   res++;
                   setIslands(grid,i,j);//ok
               }
           }
        }
       return res;
    }

    void setIslands(vector<vector<char>>& grid, int i, int j) {

    	if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!='1') {
    		return;
    	}

    	grid[i][j] = '2';
    	setIslands(grid,i-1,j);
    	setIslands(grid,i+1,j);
    	setIslands(grid,i,j-1);
    	setIslands(grid,i,j+1);

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
