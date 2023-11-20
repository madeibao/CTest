
// 幂运算计算

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {

        if(n==0) {
            return 1;
        }
        if(n==1) {
            return x;
        }

        if(n==-1) {
            return 1/x;
        }

        double half = myPow(x,n/2);
        double rest = myPow(x,n%2);

        return rest*half*half;

    }
};

int main(int argc, char** argv) {

    Solution s2;
    cout<<s2.myPow(12.000,2)<<endl;

    return 0;
}
