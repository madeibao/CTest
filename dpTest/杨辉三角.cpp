

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> res(numRows);
        for(int i = 0; i < numRows; ++i)
        {
            res[i].resize(i+1,1);               //初始化每行元素的值均为1，元素个数为i+1
            for(int j = 1 ; j < i ; ++j)        //每行对于除开首和尾的位置
                res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
        return res;
    }
};


int main() {
    Solution s;
    int numRows = 3;
    vector<vector<int>> res;
    res = s.generate(numRows);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
