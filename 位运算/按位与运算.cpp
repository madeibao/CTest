
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {

        while(right>left) {
            right = right&(right-1);
        }
        return right;
    }
};

int main() {
    int left = 5, right = 7;
    Solution s2;
    cout<<s2.rangeBitwiseAnd(left,right);
    return 0;
}
