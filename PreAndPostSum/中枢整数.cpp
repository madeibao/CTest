

#include "iostream"
#include "bits/stdc++.h"

using namespace std; //

class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) {
            return 1;
        }

        int sum = (1+n)*n/2;
        int cur = 0;
        for(int i=1;i<=n;i++) {
            cur+=i;
            if(cur==sum-cur+i) {
                return i;
            }
        }

        return -1;
    }
};

int main() {

    int n = 8;
    Solution s2;
    cout<<s2.pivotInteger(n)<<endl;
    return 0;
}
