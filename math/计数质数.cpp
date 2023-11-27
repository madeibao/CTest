
// 判断一个范围内有多少个质数

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        vector<bool> prime(n,1);
        int cnt = 0;
        for(int i=2;i<n;i++) {
            if(prime[i]) {
                cnt++;
                if((long long)i*i<n) {
                    for(long long j=i*i;j<n;j+=i) {
                        prime[j] = 0;
                    }
                }
            }
        }

        return cnt;
    }
};

int main(int argc, char** argv) {


    int n = 10;
    Solution s2;
    cout<<s2.countPrimes(n)<<endl;
    return 0;
}
