
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool myfun(string a, string b) {
        string newab = a + b;
        string newba = b + a;
        if (newab < newba) {
            return true;
        }
        return false;
    }

    string minNumber(vector<int> &nums) {
        vector<string> numstr;
        string result;

        for (auto num : nums) {
            numstr.push_back(to_string(num));
        }

        sort(numstr.begin(), numstr.end(), myfun);

        for (auto s : numstr) {
            result.append(s);
        }

        return result;
    }
};


int main() {
    vector<int> num {10,2};
    Solution s;
    cout<<s.minNumber(num);
}
