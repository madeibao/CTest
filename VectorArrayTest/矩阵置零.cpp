


#include <iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0_flag = false;
        bool column0_flag = false;

        // 判断第一行是否包含0
        for(int j = 0 ; j < n ; j++) {
            if(matrix[0][j] == 0) {
                row0_flag = true;
            }
        }


        // 判断第一列是否包含0
        for(int i = 0 ; i < m ; i++) {
            if(matrix[i][0] == 0) {
                column0_flag = true;
            }
        }


        // 第一行中，第一列中的对应的位置0
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }



        for(int i = 1 ; i < m ; i++) {
            if(matrix[i][0] == 0){
                for(int j = 1 ; j < n ; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j = 1 ; j < n ; j++) {
            if(matrix[0][j] == 0){
                for(int i = 1 ; i < m ; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 如果第一行元素中包含0
        if(row0_flag) {
            for(int j = 0 ; j < n ; j++) {
                matrix[0][j] = 0;
            }
        }

        // 如果第一列的元素中包含0
        if(column0_flag) {
            for(int i = 0 ; i < m ; i++){
                matrix[i][0] = 0;
            }
        }
    }
};


int main(int argc, char** argv) {


	vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
	Solution s2;
	vector<vector<int>> res;
	s2.setZeroes(matrix);
	for(auto i:matrix) {
		for(auto j:i) {
			cout<<j<< " ";
		}
		cout<<endl;
	}
	return 0;
}
