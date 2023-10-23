

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {

        reverse(s.begin(), s.begin() + n);
        reverse(s.begin()+n, s.end());
        reverse(s.begin(),s.end());

        return s;
    }
};

int main(int argc, char* argv[]) {

    string s = "abcdefg";
    int k = 2;
    Solution s2;
    cout<<s2.reverseLeftWords(s,k)<<endl;
    return 0;
}


