
#include "iostream"
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    	int m = matrix.size();

        // 先上下镜像
  		for(int i=0;i<m;i++) {
    		for(int j=0;j<m/2;j++) {
    			swap(matrix[i][j],matrix[i][m-1-j]);
    		}
    	}

        // 对称轴翻转
    	for(int i=0;i<m;i++) {
    		for(int j=0;j<m;j++) {
    			swap(matrix[i][j],matrix[j][i]);
    		}
    	}

    }
};

int main(int argc, char** argv) {
	vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60},{1,2,3,4}};

	Solution s;
	s.rotate(matrix);
	for(int i=0;i<matrix.size();i++) {
		for(int j=0;j<matrix[0].size();j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}


