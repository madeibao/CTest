




#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        stringstream iss(text);

        vector<string> vs;
        string word;
        char token = ' ';
        while(getline(iss, word, token)) {
            vs.push_back(word);
        }

        for(int i=0;i<vs.size();i++) {
            if(!helper(brokenLetters, vs[i])) {
                res++;
            }
        }

        return res;
    }

    bool helper(string allowed, string str) {

        for(int i=0;i<str.size();i++) {
            if(allowed.find_first_of(str[i]) != string::npos) {
                return true;
            }
        }

        return false;
    }
};


int main()
{
    string text = "hello world", brokenLetters = "ad";
    Solution s2;
    cout<<s2.canBeTypedWords(text,brokenLetters)<<endl;
    return 0;
}






