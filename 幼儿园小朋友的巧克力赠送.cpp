
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	int *h  =new int[n];
	for(int i=0; i<n;i++) {
		cin>>h[i];
	}
	int m;
	int *w  = new int[m];
	for(int i=0; i<m;i++) {
		cin>>w[i]; //
	}
	int res=0;
	int i=0,j=0;
	while(i<n&&j<m) {
		if(h[i]<=w[j]) {
			res+=1;
			i++;
			j++;
		}
		else {
			j+=1; 
		}
	}
	cout<<res<<endl;
	return 0;

}


















