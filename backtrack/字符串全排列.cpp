
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> rec;
    vector<bool> vis;

    void backtrack(const string& goods, int i, int n, string& perm) {
        if (i == n) {
            rec.push_back(perm);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (vis[j] || (j > 0 && !vis[j - 1] && goods[j - 1] == goods[j])) {
                continue;
            }
            vis[j] = true;
            perm.push_back(goods[j]);
            backtrack(goods, i + 1, n, perm);
            perm.pop_back();
            vis[j] = false;
        }
    }

    vector<string> goodsOrder(string goods) {
        int n = goods.size();
        vis.resize(n);
        sort(goods.begin(), goods.end());
        string perm;
        backtrack(goods, 0, n, perm);
        return rec;
    }
};

int main() {

    string str = "abc";
    Solution s2;
    vector<string> res;
    res = s2.goodsOrder(str);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}
