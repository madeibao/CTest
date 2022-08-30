

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 通过转化之后的解法内容。
class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) {return 1;}
    if (n == 1) {return x;}
    long long N = n;
    if (N < 0) {
      N = -N;
      x = 1/x;
    }
    double half = myPow(x, int(N/2));
    return N%2 ? half*half*x : half*half;
  }
};


int main(int argc, char* argv[])  {
    Solution s;
    double x = 10.0;
    int n =2;
    cout<<s.myPow(x, n)<<endl;
    return 0;
}
