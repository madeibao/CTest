

#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here

        unordered_map<char, char> map = {{')', '('}, {']','[' },{'}','{'}};
        stack<char> stack2;


        for(int i=0;i<s.size();i++) {
        	if(s[i]=='('||s[i]=='['||s[i]=='{') {
        		stack2.push(s[i]);
        	}

        	else if(stack2.size()!=0 && stack2.top()==map[s[i]]) {
        		stack2.pop();
        	}
        	else {
        		return false;
        	}
        }

        return stack2.empty();
    }
};


int main(int argc, char* argv[]) {

	string s22="()()";
	Solution s;
	cout<<s.isValid(s22)<<endl;
	return 0;
}
