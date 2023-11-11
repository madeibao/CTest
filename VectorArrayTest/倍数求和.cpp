
// ----------------------------------------------------------------
// 容斥原理

#include <cstdio>
#include <iostream>
using namespace std;


class Solution {
private:
    int helper(int n, int k){
        int cnt = n / k;    // cnt * k 为小于等于n的最大数字
        return (k + cnt * k) * cnt / 2; // 等差数列求和公式
    }
public:
    int sumOfMultiples(int n) {
        return helper(n, 3) + helper(n, 5) + helper(n, 7) - helper(n, 3*5) - helper(n, 3 * 7) - helper(n,5*7) + helper(n, 3 * 5 * 7);
    }
};


int main(int argc, char**argv) {

    int n = 7;
    Solution s2;
    cout<<s2.sumOfMultiples(n)<<endl;
    return 0;
}
