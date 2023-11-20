
#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int countPrimes(int n) {

//         vector<int> isPrime(n, 1);

//         int ans = 0;

//         for(int i=2;i<n; ++i) {
//             if(isPrime[i]) {
//                 ans += 1;
//                 if((long long)i * i < n) {
//                     for(int j = i*i;j<n;j+=i) {
//                         isPrime[j] = 0;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }

// };


int main() {

    int n = 7;
    Solution s2;
    cout<<s2.countPrimes(n)<<endl;

    return 0;
}
