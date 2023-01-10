

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
    int solve(vector<vector<char> >& grid) {
        // write code here
       int res = 0;
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
               if(grid[i][j]=='1'){
                   res++;
                   dfs(grid,i,j);//ok
               }
           }
       }
       return res;
    }
    void dfs(vector<vector<char>>& grid,int x,int y){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]=='0')
            return;
        grid[x][y]='0';
        dfs(grid,x-1,y);
        dfs(grid,x,y-1);
        dfs(grid,x+1,y);
        dfs(grid,x,y+1);
    }
    void bfs(vector<vector<char> >& grid,int x,int y){
        queue<pair<int,int>> qu;
        pair<int,int> p(x,y);
        qu.push(p);
        while(!qu.empty()){
            p = qu.front();
            qu.pop();
            int i= p.first;
            int j= p.second;
            grid[i][j]=='0';
            if(i-1>=0 && grid[i-1][j]=='1'){
                p.first = i-1;
                p.second = j;
                qu.push(p);
            }
            if(j-1>=0 && grid[i][j-1]=='1'){
                p.first = i;
                p.second = j-1;
                qu.push(p);
            }
            if(i+1<grid.size() && grid[i+1][j]=='1'){
                p.first = i+1;
                p.second = j;
                qu.push(p);
            }
            if(j+1<grid[0].size() && grid[i][j+1]=='1'){
                p.first = i;
                p.second = j+1;
                qu.push(p);
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
	cout<<s.solve(grid)<<endl;
	return 0;
}
