

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isValid(string strs) {
        stack<char> sta;
        unordered_map<char, char> map2 = {{')', '('}, {']','[' },{'}','{'}};

        for(int i = 0; i < strs.length(); i++) {
        	if(strs[i] == '('||strs[i] == '{'||strs[i] == '[') {
        		sta.push(strs[i]);
        	}
        	else if(!sta.empty()&&sta.top() == map2[strs[i]]) {
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