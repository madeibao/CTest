


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s2) {

        unordered_map<char, char> map2 = {{']','['},{'}','{'},{')','('}};

        stack<char> stack2;
        for(int i=0;i<s2.size();i++) {
            if(s2[i] == '(' || s2[i] == '{' || s2[i] == '[') {
                stack2.push(s2[i]);
            }
            else if(!stack2.empty()&&stack2.top()==map2[s2[i]]) {
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

    string str ="(){}[]";
    Solution s2;
    cout<<s2.isValid(str)<<endl;
    return 0;
}
