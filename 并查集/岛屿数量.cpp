
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int a[310][310];//并查集
    int m,n;
    //初始化并查集，将二维坐标映射到一个整数
    void init_set() {
         for(int i=0;i<m;i++)
         for(int j=0;j<n;j++)
          a[i][j]=i*n+j;
    }
    int find_set(int x)//并查集递归查找函数
    {
        int xx=x/n;
        int yy=x%n;
        return a[xx][yy]==x?x:find_set(a[xx][yy]);
    }
    void union_set(int x,int y)//并查集合并
    {
        x=find_set(x);
        y=find_set(y);
        if(x!=y){ int xx1=x/n,yy1=x%n;
        int xx2=y/n,yy2=y%n;
        a[xx1][yy1]=a[xx2][yy2];}
    }
    int numIslands(vector<vector<char>>& grid) {
            m=grid.size();
            n=grid[0].size();
            init_set();
            for(int i=0;i<m;i++)//扫描grid数组并合并连通岛屿
             for(int j=0;j<n;j++)
             {
                 if(grid[i][j]=='1')
                 {
                     if(j>0)
                     {
                        if(grid[i][j-1]=='1')union_set(a[i][j-1],a[i][j]);
                     }
                      if(i>0)
                     {
                         if(grid[i-1][j]=='1')union_set(a[i-1][j],a[i][j]);
                     }
                 }
             }
             int ans=0;
             for(int i=0;i<m;i++)
             for(int j=0;j<n;j++)
             if(grid[i][j]=='1'&&a[i][j]==i*n+j)ans++;//若属于同一岛屿，则递归最终找到的根节点一定满足该式，只判断根节点
             return ans;
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
