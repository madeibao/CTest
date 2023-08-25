


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s2) {
        stack<char> stk;
        for(char c : s2) {
            if(c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if(stk.empty()) return false;
                if(c == ')' && stk.top() != '(') return false;
                if(c == '}' && stk.top() != '{') return false;
                if(c == ']' && stk.top() != '[') return false;
                stk.pop();
            }
        }
        return stk.empty();
        
    }
};

int main() {

    string str ="(){}[]";
    Solution s2;
    cout<<s2.isValid(str)<<endl;
    return 0;
}