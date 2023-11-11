

#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calc(const string& a) {
        int val = 0;
        for (char c : a) {
            val |= (1 << (c - 'a'));
        }
        return val;
    }
    bool check(const string& a, const string& b) {
        return calc(a) == calc(b);
    }
    int similarPairs(vector<string>& ws) {
        int n = ws.size(), sum = 0;
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) 
                if (check(ws[i], ws[j])) sum++;
        return sum;
    }
};


int main() {

    vector<string>words = {"aba","aabb","abcd","bac","aabc"};
    Solution s2;
    cout<<s2.similarPairs(words)<<endl;
    return 0;
}