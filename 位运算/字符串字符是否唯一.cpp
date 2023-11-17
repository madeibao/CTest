
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        int mask = 0;
        for (char c : astr) {
            int i = c - 'a';
            if (mask >> i & 1) {
                return false;
            }
            mask |= 1 << i;
        }
        return true;
    }
};


int main() {

    string s = "abc";
    Solution s2;
    cout<<s2.isUnique(s)<<endl;
    return 0;
}
