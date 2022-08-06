


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        for (int n = 1; (n + 1) * n <= 2 * N; ++n) {
            if ((N - n * (n - 1) / 2) % n == 0) {
            	res++;
            }
        }
        return res;
    }
};

int main(int argc,char*argv[])  {
	int N = 5;
	Solution s;
	cout<<s.consecutiveNumbersSum(N)<<endl;
	return 0;
}








