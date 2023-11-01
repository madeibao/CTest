
// 回溯法解决

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    string s;
    vector<string> result;
    //                          0   1    2      3
    vector<string> letterMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtracking(string digits, int index) {

        if(index==digits.size()) {
            result.push_back(s);
            return;
        }

        int digit = digits[index]-'0';
        string letters = letterMap[digit];

        for(int i=0;i<letters.size();i++) {
            s.push_back(letters[i]);
            backtracking(digits,index+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return result;
        backtracking(digits, 0);
        return result;
    }
};

int main() {

    string digits = "23";
    Solution solution;
    vector<string> res;
    res =solution.letterCombinations(digits);
    for(auto i:res) {
        cout<<i<<" ";
    }

    return 0;
}
