

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        priority_queue<long,vector<long>,greater<long>> queue;
        queue.push(1);

        for(int i=1;i<n;i++) {

            long t = queue.top();
            queue.pop();

            while(!queue.empty()&&queue.top()==t) {
                queue.pop();
            }

            for(int j=0;j<primes.size();j++) {
                queue.push(primes[j]*t);
            }
        }

        return queue.top();

    }
};

int main() {

    int n = 12;
    vector<int> primes = {2,7,13,19};

    Solution s2;

    cout<<s2.nthSuperUglyNumber(n,primes)<<endl;
    return 0;
}
