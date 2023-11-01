


#include "iostream"
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int i = 0,j = n-1;
        while(i < m && j >= 0) 
        {
            if(matrix[i][j] == target) 
                return true;
            if(matrix[i][j] < target) 
                ++ i;
            else 
                -- j;
        }
        return false;
    }
};



int main(int argc, char** argv) {

	vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	int target(3);
	Solution s2;
	cout << s2.searchMatrix(target)<<endl;
	return 0;
}