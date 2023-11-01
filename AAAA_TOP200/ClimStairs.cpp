

#include "iostream"
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int climbStairs(int n) {

    	// 递归一定有结束 的条件
        if(n<=1) {
            return n;
        }
        vector<int> res(n+1);
        res[0]= 0;
        res[1]= 1;
        res[2]= 2;

        for(int i=3;i<=n;i++) {
            res[i]= res[i-1]+res[i-2];
        }
        return res[n];
    }
};

int main(int argc, char** argv) {

	Solution s2;
	cout<<s2.climbStairs(3)<<endl;
	return 0;
}