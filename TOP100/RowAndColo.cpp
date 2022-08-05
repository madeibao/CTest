


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

    	int m = grid.size();
    	int n = grid[0].size();

    	vector<vector<int> > dp (m, vector<int>(n,0));

    	for(int i=0; i<m; i++) {
    		for(int j = 0; j<n; j++) {
    			dp[j][i] = grid[i][j];
    		}
    	}

    	int ans = 0;
        for(auto i:grid) {
            for(auto j:dp) {
                if(i==j) {
                    ans++;
                }
                else {
                    continue;
                }
            }
        }

    	return ans;

    }
};


int main(int argc, char** argv) {

	vector<vector<int> > matrix= {{3,2,1},{1,7,6},{2,7,7}};
	Solution solution;
	cout<<solution.equalPairs(matrix)<<endl;
	return 0;
}
