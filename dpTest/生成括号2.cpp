

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<string> res;
	vector<string> gengerate(int n) {
		string str = "";
		helper(str, n,n);
		return res;
	}

	void helper(string str,int left, int right) {

		if(left>right){
			return;
		}

		if(left<0||right<0) {
			return;
		}

		if(left==0&&right==0) {
			res.push_back(str);
		}
		helper(str+"(", left-1,right);
		helper(str+")",left, right-1);
	}

};
int main(int argc, char** argv) {

	int n = 3;
	vector<string> res;
	Solution s;
	res = s.gengerate(n);
	for(auto i :res) {
		cout<<i<<endl;
	}
	return 0;
}