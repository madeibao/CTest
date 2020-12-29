


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
	if(n<2||n%2==0) {
		return n==2;
	}

	int limit = sqrt(n);
	for(int i=3;i<=limit;i++) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}


int main(int argc, char* argv[]) {
	int n = 13;
	cout<<isPrime(n)<<endl;
	return 0;
}