
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int reverse(int x) {
        // write code here
        ll res = 0;
        while(x!=0) {
            res = res*10+x%10;
            x/=10;
            if(res >= INT_MAX || res <= INT_MIN)
                return 0;
        }
        return res;
    }
};


int main(int argc, char* argv[]) {

	int x =123;
	Solution s;
	cout<<s.reverse(x)<<endl;
	return 0;
}