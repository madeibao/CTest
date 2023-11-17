

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main(int argc, char** argv) {

    Solution s2;
    cout<<s2.isPowerOfThree(9)<<endl;
    return 0;
}
