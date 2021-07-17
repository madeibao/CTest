
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> strs;
        backtrace(strs,"",n,0);
        return strs;
    }

    // 最终会改变 字符串数组的内容，所以用引用类型。
    void backtrace(vector<string>& strs,string str,int left,int right) {
        if (left == 0 && right == 0) {
            strs.push_back(str);
            return;
        }

        if (left > 0) backtrace(strs,str+"(",left-1,right+1);
        if (right > 0) backtrace(strs,str+")",left,right-1);
    }
};



int main(int argc, char** argv) {

	// n 必须进行初始化操作。
	int n=3;
	vector<string> res;
	Solution s;

	res = s.generateParenthesis(n);
    for(auto i:res) {
        cout<<i<<endl;
    }
    return 0;
}
