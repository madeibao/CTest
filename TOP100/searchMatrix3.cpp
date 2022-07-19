
// ----------------------------------------------------------------
// 二分查找算法来确定矩阵中的一个数值

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {

public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		// 相当于搜索每一行内容。
		for(auto const& ma:matrix) {

			// 然后对每一行的内容来进一步的搜索。
			auto it = lower_bound(ma.begin(), ma.end(),target);
			if(it!= ma.end()&& *it==target) {
				return true;
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
