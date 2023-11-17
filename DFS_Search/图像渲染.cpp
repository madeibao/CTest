
#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void DFS(int x,int y,int newColor,vector<vector<int>>&image,int init){
        if(x>=0&&x<image.size()&&y>=0&&y<image[0].size()&&image[x][y]==init){
            image[x][y]=newColor;
            DFS(x+1,y,newColor,image,init);
            DFS(x-1,y,newColor,image,init);
            DFS(x,y+1,newColor,image,init);
            DFS(x,y-1,newColor,image,init);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //需要特殊的处理一下!!!!!
        if(image[sr][sc]==newColor) {
            return image;
        }
        DFS(sr,sc,newColor,image,image[sr][sc]);
        return image;
    }
};

int main(int argc, char** argv) {

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    Solution s2;
    vector<vector<int>> res;
    res = s2.floodFill(image, sr,sc,newColor);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
