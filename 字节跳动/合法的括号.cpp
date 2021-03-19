

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool legalBracket(string s) {
        unordered_map<char, char> map2 = {{')', '('}, {']','[' },{'}','{'}};

        stack<char> stack2;
        for(char c:s) {
            if(c == '('||c=='['||c=='{') {
                stack2.push(c);
            }
            else if(stack2.size()!=0 and stack2.top()==map2[c]) {
                stack2.pop();
            }
            else {
                return false;
            }
        }
        return stack2.empty();
    }
};

int main(int argc, char** argv) {

    Solution s;
    string str2 = "()(){}";
    cout<<s.legalBracket(str2)<<endl;
//    cout<<s.legalBracket(str2)<<endl;
    return 0;
}


