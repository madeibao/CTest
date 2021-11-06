
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> strs;

		if(n<=0) {
			return strs;
		}

		helper(strs, n, n,"");
		return strs;
	}

	void helper(vector<string>& strs, int left, int right, string temp) {

		if(left<0||right<0||left>right) {
			return;
		}

		if(left==0&&right==0) {
			strs.push_back(temp);
		}

		helper(strs,left-1,right,temp+"(");
		helper(strs,left,right-1,temp+")");
	}
};


int main() {

	int n =3;
	vector<string> res;
	Solution s;
	res = s.generateParenthesis(n);
	for(auto i:res) {
		cout<<i<<endl;
	}

	return 0;
}

