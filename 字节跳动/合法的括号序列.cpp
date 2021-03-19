

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here


        unordered_map<char, char> map2 = {{')', '('}, {']','[' },{'}','{'}};
        stack<char> stack2;
        for(char c:s) {

        	if(c == '('||c=='['||c=='{') {
        		stack2.push(c);
        	}
        	else if(stack2.size()>0 && stack2.top()==map2[c]) {
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

	Solution s;
	string str2= "()(){}";
	cout<<s.isValid(str2)<<endl;

	return 0;
}
