

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> exist(26);
        for (auto c : sentence) {
            exist[c - 'a'] = true;
        }
        for (auto x : exist) {
            if (x == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    Solution s;
    cout<<s.checkIfPangram(sentence)<<endl;
    return 0;
}
