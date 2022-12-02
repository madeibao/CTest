


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	if (n<=0) {
    		return res;
    	}
    	helper(res, "", n,n);
    	return res;
    }

    void helper(vector<string>& res, string temp, int left, int right) {
    	if(left<0&&right<0) {
    		return;
    	}
    	if(left==0&&right==0) {
    		res.push_back(temp);
    	}
    	helper(res, temp+")",left-1,right);
    	helper(res, temp+")",left,right-1);
    }
};



int main(int argc, char** argv) {

	int n(3);
	vector<string> res;
	Solution s;
	res = s.generateParenthesis(n);
	for(auto i:res) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}