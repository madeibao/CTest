
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int getNum(int n) {

		int res =0;
		while (n>0) {	
			res+=n/5;
			n = n/5;
		}

		return res;
	}
};

int main(int argc, char* argv[]) {
	int n = 10;
	Solution s;
	cout<<s.getNum(n)<<endl;

	return 0;
}