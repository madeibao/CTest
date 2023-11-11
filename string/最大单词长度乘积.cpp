

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {

        int ans = 0;
        for(int i=0;i<words.size();i++) {
            string word1 = words[i];
            for(int j=i+1;j<words.size();j++) {
                string word2 = words[j];
                if(!hasSameChar(word1,word2)) {
                    ans = max(ans, int(word1.size()*word2.size()));
                }
            }
        }
        return ans;
    }

    bool hasSameChar(const string word1, const string word2) {
        for(char c:word1) {
            if(word2.find(c)!=string::npos) {
                return true;
            }
        }
        return false;
    }
};

int main() {

    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution s2;
    cout<<s2.maxProduct(words)<<endl;

    return 0;
}
