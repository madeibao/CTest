#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //先沿斜对角线翻转
        int n = matrix.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                swap(matrix[i][j],matrix[j][i]);
        //再沿垂直竖线翻转
        for(int i = 0;i < n; i++)
            for(int j = 0, k = n - 1; j < k ; j++, k--) //类似于双指针，由两端向中心靠齐
                swap(matrix[i][j],matrix[i][k]);
    }
};


int main() {

    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s2;
    vector<vector<int>> res;
    s2.rotate(nums);
    for(auto i:nums) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}




