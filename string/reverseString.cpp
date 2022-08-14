
#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
    stack<char>dp;
    int len=s.size();
    string str="";
	int bo=0;
    for(int i=len-1;i>=0;i--) {
	   if(s[i]==' ') {
	       while(!dp.empty()) {
	           bo=1;
	           str+=dp.top();
	           dp.pop();
	       }
	   }
	   else {
	       if(bo) {
			  str+=' ';
	          bo=0;
	       }
	       dp.push(s[i]);
	   }
    }

	while(!dp.empty()) {
           str+=dp.top();
           dp.pop();
       }
       return str;
    }
};


int main(int argc, char* argv[]) {

	string s = "the sky is blue";
	Solution s2;
	cout<<s2.reverseWords(s)<<endl;

	return 0;
}


