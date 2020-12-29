


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {

            if(matrix.empty()) {
                return false;
            }
                // return false;

            //右上角
            int row = 0;
            int col = matrix.at(0).size() - 1;

            //左下角
            int end_row = matrix.size() - 1;
            int end_col = 0;

            while (row <= end_row && col >= end_col) {
                if (matrix.at(row).at(col) == target) {
                    return true;
                }
                 //去左边部分找
                else if(target < matrix.at(row).at(col)) {
                    --col;
                }
                //去下边部分找
                else if (target > matrix.at(row).at(col)) {
                    ++row;
                }
            }
            
            // 默认的条件下是返回false的。
            return false;
        }
};

int main() {
    Solution s;
    vector<vector<int> > nums = {{1,   4,  7, 11, 15},
                                 {2,   5,  8, 12, 19},
                                 {3,   6,  9, 16, 22},
                                 {10, 13, 14, 17, 24},
                                 {18, 21, 23, 26, 30}};
      
    int target  = 5;
    cout<<s.searchMatrix(nums, target)<<endl;
    return 0;
}



