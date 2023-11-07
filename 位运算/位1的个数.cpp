
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {

        int res= 0;
        while(n!=0) {
            n =n&(n-1);
            res+=1;
        }
        return res;
    }
};

int main() {
    uint32_t n = 11111111111111111111111111111101;
    Solution s2;
    cout<<s2.hammingWeight(n)<<endl;

    return 0;
}