
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int ans = 0;

        //
        s += ' ';
        for (int i = 1; i < s.size(); i++)
            if (s[i] == ' ' && s[i - 1] != ' ') ans++;
        return ans;
    }
};


int main(int argc, char** argv) {

    string str = "Hello, my name is John";
    Solution s;
    cout<<s.countSegments(str)<<endl;
    return 0;
}
