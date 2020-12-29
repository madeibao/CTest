
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
	public:
		bool isSpecialMatrix(vector<vector<int>> matrix) {

			int m = matrix.size();
			int n = matrix[0].size();
			if(m==1 || n==1) {
				return true;
			}
			for(int i=1;i<m;i++) {
				for(int j=1;j<n;j++) {
					if(matrix[i][j]!=matrix[i-1][j-1]) {
						return false;
					}
				}
			}
			return true;
		}

};
int main(int argc, char**args) {
	vector<vector<int> > res = {{1,2,3,4},
								{5,1,2,3},
								{9,5,1,2},};
	Solution s;
	cout<<s.isSpecialMatrix(res)<<endl;
	return 0;
}