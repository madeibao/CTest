

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		double re = 1;

		long a = n;// 为了防止整形越界
		if(a<0) {
			x= 1/x;
			a= -a;
		}

		while(a) {

            // 如果是奇数字。
			if(a&1==1) {
				re*=x;
			}
			x*=x;
			a>>=1;
		}
		return re;
	}
};

int main(int argc, char** argv) {

	double x = 2.0;
	int n = 10;
	Solution s;
	cout<<s.myPow(x,n)<<endl;
	return 0;
}
