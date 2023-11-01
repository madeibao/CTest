

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.emplace_back(path);
            return;
        }
        for (int i = startIndex; i <= n; ++i) {
            path.emplace_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};


int main() {

    int n =4, k=2;
    Solution s2;

    vector<vector<int>> res;
    res = s2.combine(n,k);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
