

#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size(), i = 0;
        if (sentence[0] != sentence[n - 1]) return false;

        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) 
                return false;
        }

        return true;
    }
};

int main(int argc, char** argv) {

    string sentence = "leetcode exercises sound delightful";
    Solution s;
    cout<<s.isCircularSentence(sentence)<<endl;
    return 0;
}