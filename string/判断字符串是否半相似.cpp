
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {

        string stra = s.substr(0,s.size()/2);
        string strb = s.substr(s.size()/2);

        if(helper(stra)==helper(strb)) {
            return true;
        }

        return false;
    }

    int helper(string s) {
        set<char> str = {'a','e','i','o','u','A','E','I','O','U'};
        int res = 0;
        for(auto i:s) {
            if(str.find(i)!=str.end()) {
                res++;
            }
        }
        return res;
    }
};

int main() {

    Solution s2;
    string str = "book";
    cout<<s2.halvesAreAlike(str)<<endl;
    return 0;
}
