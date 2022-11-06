




#include<iostream>
#include<bits/stdc++.h>

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

    int n = 15;
    Solution s;
    cout<<s.hammingWeight(n);
    return 0;
}


