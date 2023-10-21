


class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        i = word.find(ch)
        return word[:i+1][::-1]+word[i+1:]



#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (string& s : words) ans += !s.find(pref); //find(pref) == 0代表以pref开始
        return ans;
    }
};

int main() {
    
    vector<string> words = {"pay","attention","practice","attend"};
    string pref = "at";
    Solution s2;
    cout<<s2.prefixCount(words,pref)<<endl;
    return 0;
}