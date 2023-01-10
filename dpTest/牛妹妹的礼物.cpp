
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * 
     * @param presentVolumn int整型vector<vector<>> N*M的矩阵n行m列，每个元素是这个地板砖上的礼物体积
     * @return int整型
     */
    int selectPresent(vector<vector<int> >& presentVolumn) {
        // write code here
        int n=presentVolumn.size();
        int m=presentVolumn[0].size();
        if(n==0||m==0)
            return 0;
        int x,y,z;
        for(int i=1;i<m;i++) {
            presentVolumn[0][i] += presentVolumn[0][i-1];
        }
        for(int j=1;j<n;j++) {
            presentVolumn[j][0]+=presentVolumn[j-1][0];
        }
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                x=presentVolumn[i][j-1]+presentVolumn[i][j];
                y=presentVolumn[i-1][j-1]+presentVolumn[i][j];
                z=presentVolumn[i-1][j]+presentVolumn[i][j];
                presentVolumn[i][j]=min(min(x, y), z);
            }
        }
        return presentVolumn[n-1][m-1];
    }
};


int main(int argc, char** argv) {

    vector<vector<int>> res = {{1,2,3,},{2,3,4}};
    Solution s;
    cout<<s.selectPresent(res)<<endl;

    return 0; //
}