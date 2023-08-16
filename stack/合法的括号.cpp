
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        unordered_map<char,char> map2 = {{')','('},{']','['},{'}','{'}};
        stack<char> stack2;
        for(int i=0;i<s.length();i++) {
        	if(s[i]=='('||s[i]=='['||s[i]=='{') {
        		stack2.push(s[i]);
        	}
        	else if(!stack2.empty()&&map2[s[i]]==map2.top()) {
        		stack2.pop();
        	}
        	else {
        		return false;
        	}
        }
        return stack2.empty();
    }
};


int main() {

	string s = "()[]{{[]}}";
	Solution s2;
	cout<<s2.isValid(s)<<endl;
    return 0;
}
