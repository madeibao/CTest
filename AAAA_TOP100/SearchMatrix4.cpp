

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
		if(matrix.size()==0||matrix[0].size()==0) {
			return false;
		}

		
		int m = 0;
		int n = matrix[0].size()-1;

		int i=m;
		int j=n;
		// 从右上角的位置查找
		while (i<matrix.size()&&j>=0) {
			if(matrix[i][j]==target) {
				return true;
			}
			else if(matrix[i][j]<target) {
				i++;
			}
			else {
				j--;
			}
		}

		return false;
    }
};  
	
int main(int argc, char** argv) {

	vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	int target(3);
	Solution s2;
	cout << s2.searchMatrix(matrix, target)<<endl;
	return 0;
}
