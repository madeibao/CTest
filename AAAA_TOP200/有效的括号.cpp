
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {

    	unordered_map<char,char> map2 = {{']','['},{')':'('},{'}','{'}};

    	stack<char> stack2;

    	for(auto i:s) {
    		if(i=='[' || i=='(' || i=='{') {
    			stack2.push_back(i);
    		}
    		else if(!stack2.empty()&&map2[i]==stack2.top()) {
    			stack2.pop();
    		}
    		else {
    			return false;
    		}
    	}

    	return stack.empty();
    }
};

int main() {

	string str = "()[]{}";
	Solution s2;
	cout<<s2.isValid(str)<<endl;
	return 0;
}