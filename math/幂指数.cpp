

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

/**
class Solution {
public:
    
    double qpow(double a, long long b) {
        double res = 1;
        while(b){
            if(b&1) res = res*a;
            b >>= 1;
            a *= a;
        }
        return res;
    }
    
    
    double myPow(double x, long long n) {
        if(n == 0) return 1;
        if(n > 0) return qpow(x,n);
        if(n < 0) return 1/qpow(x,-n);
        return 1.0;
    }
};
*/

class Solution2 {

public:
	double myPow(double x, int n) {
		double res =1;
		bool flag = (n>0);
		n = abs(n);

		while(n>0) {

			// 如果n是奇数字。
			if(n&1) {
				res = res*x;
			}
			x = x*x;
			n >>=1;
		}

		return flag>0?res:1/res;
	}

};
int main(int argc, char** argv) {

	Solution2 s2;
	cout<<s2.myPow(10.0,2)<<endl;
	return 0;
}


