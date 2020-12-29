



#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m ={{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for(unsigned int i = 0; i <= num.size() / 2; ++i) {
            if (m[num[i]] != num[num.size() - i - 1]) return false;
        }
        return true;
    }
};

int main() {
    string ss= "69";
    Solution s2;
    cout<<s2.isStrobogrammatic(ss)<<endl;
    return 0;
}
