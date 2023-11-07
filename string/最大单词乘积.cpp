

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums;
        for (auto& a : words) {
            int temp = 0;
            for (auto& i : a) {
                temp |= 1 << (i - 'a');
            }
            nums.push_back(temp);
        }
        
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!(nums[i] & nums[j])) {
                    res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};

int main() {

    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution s2;
    cout<<s2.maxProduct(words)<<endl;

    return 0;
}
