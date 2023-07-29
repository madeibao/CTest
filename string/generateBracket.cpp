
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<string> generate(int n) {
		vector<string> res;
		if(n<0) {
			return res;
		}	
		helper(res, "", n, n);
		return res;
	}

	void helper(vector<string> res, string temp, int left ,int right) {
		if(left < 0 || right < 0 || left > right) {
			return;
		}
		if(left == 0 && right == 0) {
			res.push_back(temp);
		}

		helper(res, temp+"(", left-1, right);
		helper(res, temp+")", left, right-1);
	}


};


int main(int argc, char** argv) {

	int n(3);
	vector<string> res;
	Solution s2;
	res = s2.generate(n);
	for(auto i:res) {
		cout<<i<<" "<<endl;
	}

	return 0;
}