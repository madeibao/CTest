
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> dict2 = {{')', '('}, {']','[' },{'}','{'}};
        stack<char> stack2;
        for(char c:s) {
            if(c=='('||c=='['||c=='{') {
                stack2.push(c);
            }
            else if(stack2.size()!=0 && stack2.top()==dict2[c]) {
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

    string str2 ="()";
    Solution s;
    cout<<s.isValid(str2);
    return 0;
}
