
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {

        //** 二维的矩阵的设置。
        // write code here
        vector<vector<int> > result(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[j][n - i - 1] = mat[i][j];
            }
        }
        return result;
    }
};



// 算法2

class Solution2 {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        // write code here
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n - 1 - j; i++) {
                int tmp = mat[j][i];
                mat[j][i] = mat[n - 1 - i][n - 1 - j];
                mat[n - 1 - i][n - 1 - j] = tmp;
            }
        }

        // 然后矩阵的转置。
        for(int j = 0; j < n / 2; j++) {
            for(int i = 0; i < n; i++) {
                int tmp = mat[j][i];
                mat[j][i] = mat[n - 1 - j][i];
                mat[n - 1 - j][i] = tmp;
            }
        }
        return mat;
    }
};


int main() {

    vector<vector<int>> res {{1,2,3},{4,5,6},{7,8,9}};
    int n = 3;
    Solution s;
    vector<vector<int> > res2;
    res2 = s.rotateMatrix(res,n );
    for(auto i:res2) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
