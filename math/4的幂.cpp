#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
    }
};

int main(int argc, char** argv) {

    Solution s2;
    cout<<s2.isPowerOfFour(16)<<endl;
    return 0;
}
