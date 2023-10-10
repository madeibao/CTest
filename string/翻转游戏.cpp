


#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                res.push_back(s.substr(0, i - 1) + "--" + s.substr(i + 1));
            }
        }
        return res;
    }
};

int main() {

    string s = "++++";
    vector<string> res;
    Solution s2;
    res = s2.generatePossibleNextMoves(s);
    for(auto b:res) {
        cout<<b<<" "<<endl;
    }
    return 0;
}
