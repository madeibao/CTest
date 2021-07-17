
// 括号生成算法。
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     *
     * @param n int整型
     * @return string字符串vector
     */


    vector<string> generateParenthesis(int n) {
    	vector<string>res;
        // write code here
        string str;
        helper(res,str,n, n);
        return res;
    }

    void helper(vector<string>& res, string str, int left, int right) {
    	if(left>right||left<0||right<0) {
    		return;
    	}
    	if(left==0&&right==0) {
    		res.push_back(str);
    		return;
    	}

    	helper(res, str+"(", left-1, right);
    	helper(res, str+")", left, right-1);
    }
};

int main(int argc, char** argv) {

	Solution s;
	int n =3;
	vector<string> res= s.generateParenthesis(n);
	for(auto i:res) {
		cout<<i<<endl;
	}

	return 0;
}
