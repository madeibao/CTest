
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3) return {};

        vector<long long> res;
        long long a = (num * 2 / 3 - 3 + 1) / 2;
        for (int i = 0 ; i < 3 ; i++) {
            res.push_back(a+i);
        }
        return res;
    }
};

int main() {

    long long num = 33;
    vector<long long > res;
    Solution s2;
    res = s2.sumOfThree(num);
    for(auto i:res) {
        cout<<i<<" ";
    }

    return 0;
}
