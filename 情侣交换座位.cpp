
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        unordered_map<int, int> memo(row.size());

        for (int i = 0; i < row.size(); i++)
            memo[row[i]] = i;

        int next = 0; // 所期望的情侣
        for (int i = 0; i < row.size(); i += 2) {
            next = (row[i] & 1) ? row[i] - 1 : row[i] + 1;
            if (row[i + 1] == next) continue;

            swap(row[i + 1], row[memo[next]]);
            swap(memo[next], memo[row[memo[next]]]);
            res++;
        }

        return res;
    }
};

int main() {

    int num;
    cin>>num;
    vector<int> res ={num*2};
    for(int i=0;i<res.size();i++) {
        cin>>res[i];
    }
    Solution s;
    cout<<s.minSwapsCouples(res)<<endl;
    return 0;
}
