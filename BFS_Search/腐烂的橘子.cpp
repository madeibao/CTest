
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int,int>> dirs{{1,0}, {-1,0}, {0,1}, {0,-1}};
    int x,y;
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> que;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==2)que.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        }

        int res =0;

        while(!que.empty()){
            int size = que.size();
            bool f = false;
            for(int i=0;i<size;++i){
                auto pp = que.front();
                que.pop();
                for(auto d:dirs){
                    int ni = pp.first+d.first;
                    int nj = pp.second+d.second;
                    if(ni<0||nj<0||ni==m||nj==n||grid[ni][nj]==2||grid[ni][nj]==0) {
                    	continue;
                    }
                    else {
                        que.push({ni,nj});
                        grid[ni][nj] = 2;
                        fresh--;
                        f = true;
                    }
                }
            }

            if(f) {
            	res++;
            }
        }
        if(fresh>0)return -1;
        return res;

    }
};


int main(int argc, char **argv) {

    vector<vector<int>> nums = {{2,1,1},{1,1,0},{0,1,1}};
    Solution s2;
    cout<<s2.orangesRotting(nums)<<endl;

	return 0;
}
