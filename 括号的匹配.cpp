#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// 判断是否为合理的括号。

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int> =m{{'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6}};
        stack<char> st;
        bool istrue=true;
        for(char c:s) {
            int flag=m[c];
            if(flag>=1&&flag<=3) {
            	st.push(c);
            }
            else {
            	if(!st.empty()&&m[st.top()]==flag-3) {
            		st.pop();
            	}
            	else {
            		istrue=false;break;
            	}
            }
        }
        if(!st.empty()) istrue=false;
        return istrue;
    }
};


int main() {
	string s = "(())";
	Solution s2;
	cout<<s2.validBracket(s)<<endl;
	return 0;
}