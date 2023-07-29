


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution2 {
public:
    char firstUniqChar(string s) {
        for(int i=0;i<s.size();i++) {
            if(s.find(s[i])==s.rfind(s[i]))
            return s[i];
        }
        return ' ';
    }
};



class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<int, int> frequency;
        for (char ch: s) {
            ++frequency[ch];
        }
        for (unsigned int i = 0; i < s.size(); ++i) {
            if (frequency[s[i]] == 1) {
                return s[i];
            }
        }
        return ' ';
    }
};

int main(int argc, char* argv[]) {

    string s = "abaccdeff";
    Solution s2;
    cout<<s2.firstUniqChar(s)<<endl;

    return 0;
}
