

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> an;
        if (matrix.empty()) {
            return an;
        }
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while ((top < (matrix.size() + 1)/2) && (left < (matrix[0].size() + 1)/2)) {
            for (int i=left; i <=right; i++) {
                an.push_back(matrix[top][i]);
            }
            for (int i=top+1; i<=bottom; i++) {
                an.push_back(matrix[i][right]);
            }
            for (int i=right-1; i>=left && top!=bottom;i--) {
                an.push_back(matrix[bottom][i]);
            }
            for (int i=bottom-1; i>=top+1 && left!=right;i--) {
                an.push_back(matrix[i][left]);
            }
            top++;
            bottom--;
            left++;
            right--;
        }
        return an;
    }
};


int main() {


	vector<vector<int> > res {{1,2,3},{4,5,6},{7,8,9}};

	vector<int> res2;
	Solution s;
	res2 = s.spiralOrder(res);
	for(int i:res2) {
		cout<<i<<" ";
	}
	return 0;
}
