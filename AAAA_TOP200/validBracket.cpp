


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isValid(string strs) {
        stack<char> sta;

        for(int i=0; i<strs.length(); i++) {
            if(strs[i] == '(' ||strs[i] == '{' || strs[i] == '[') {
                sta.push(strs[i]);
            }
            else if(strs[i] == '}'&&!sta.empty()&&sta.top() == '{'){
                sta.pop();
            }
            else if(strs[i] == ']'&&!sta.empty()&&sta.top() == '['){
                sta.pop();
            }
            else if(strs[i] == ')'&&!sta.empty()&&sta.top() == '('){
                sta.pop();
            }
            else {
                return false;
            }
        }
        return sta.empty();

	}

};

int main(int argc, char** argv) {
    string str ="()()[]{}{{}}";
    Solution s;
    cout<<s.isValid(str)<<endl;
    return 0;
}