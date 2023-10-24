




#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string res = "";
        vector<char> vec;
        int len = min(word1.size(),word2.size());
        for(int i=0,j=0;i<len;i++,j++) {
            vec.push_back(word1[i]);
            vec.push_back(word2[j]);
        }
        if(word1.size()>len) {
            for(int i=len;i<word1.size();i++) {
                vec.push_back(word1[i]);
            }
        }
        if(word2.size()>len) {
            for(int i=len;i<word2.size();i++) {
                vec.push_back(word2[i]);
            }
        }
        for(int i=0;i<vec.size();i++) {
            res+=vec[i];
        }
        return res;
    }
};


int main() {
    string word1 = "ab", word2 = "pqrs";
    Solution s2;
    cout<<s2.mergeAlternately(word1,word2)<<endl;
    return 0;
}
