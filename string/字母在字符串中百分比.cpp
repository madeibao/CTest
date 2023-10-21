

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size(), ct = 0;
        for(auto c : s)
            if(c==letter)
                ct++;
        return 100*ct/n;
    }
};

int main() {

    string s = "foobar";
    char c = 'o';
    Solution s2;
    cout<<s2.percentageLetter(s,c)<<endl;
    return 0;
}
