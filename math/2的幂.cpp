


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) {
            return true;
        }
        return (n&(n-1))==0;
    }
};

int main(int argc, char** argv) {

    Solution s2;
    cout<<s2.isPowerOfTwo(16)<<endl;
    return 0;
}