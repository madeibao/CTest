
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        set<int> digits;
        for(char c: s) {
            if(isdigit(c)) digits.insert(c - '0');
        }
        return digits.size() >= 2? *prev(prev(digits.end())): -1;
    }
};


/**
class Solution {
public:
    int secondHighest(string s) {
        set<int>digitSet;
        for(char ch:s)if(isdigit(ch))digitSet.insert(ch-'0');
        if(digitSet.size()<2)return -1;
        auto it=digitSet.rbegin();
        it++;
        return *it;
    }
};

*/



int main() {
    string s = "dfa12321afd";
    Solution s2;
    cout<<s2.secondHighest(s)<<endl;
    return 0;
}
