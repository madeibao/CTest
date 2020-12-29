

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

	long long sum, l, r, mid;
	cin>>sum;
	for(l=0, r=sum;l+1<r;) {
		mid = l + (r-l)/2;
		if(getSum(mid)==sum) {
			cout<<mid<<endl;
		}
		else if(getSum(mid)<sum) {
			l = mid;
		}
		else {
			r = mid;
		}
	}


	return 0;
}

long long getSum(int res) {
	long long temp = 0;

	while (res!=0) {
		temp += res;
		res = res/(long long)10;
	}
}