
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if(n<=0) {
			return res;
		}

		helper(n,n,"",res);
		return res;
	}

	void helper(int left, int right, string temp, vector<string>& res) {
		if(left<0||right<0||left>right) {
			return;
		}
		if(left==0&&right==0) {
			res.push_back(temp);
		}
		helper(left-1,right,temp+"(",res);
		helper(left,right-1,temp+")",res);
	}
};

int main(int argc, char** argv) {

	int n(3);
	Solution s;
	vector<string> res;
	res = s.generateParenthesis(n);
	for(auto i:res) {
		cout<<i<<endl;
	}
	return 0;
}
