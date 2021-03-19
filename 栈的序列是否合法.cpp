


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isValid(string strs) {
        unordered_map<char, char> mp = { { '}','{' }, { ')','(' }, { ']','[' } };
		stack<char> stack2;
		for(char c:strs) {
			if(c=='('||c=='['||c=='{') {
				stack2.push(c);
			}
			else {
				if(stack2.empty()||stack2.top()!=mp[c]) {
					return false;
				}
				else {
					stack2.pop();
				}
			}
		}

		return stack2.empty();
	}
};


int main() {

    Solution s;
    cout<<s.isValid("(){}");
    return 0;
}
