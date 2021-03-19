
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @param m int整型 
     * @return int整型
     */
    int ysf(int n, int m) {
        // write code here
        int alive = 0;
        for (int i = 2; i <= n; i++){
            alive = (alive + m) % i;
        }
        return alive + 1;
    }
};


int main(int argc, char* argv[]) {

	Solution s;
	int n = 5, m = 2;
	cout<<s.ysf(n, m)<<endl;
	return 0;
}