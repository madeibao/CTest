


#include <iostream>
#include <bits/stdc++.h>
const int N = 100;

using namespace std;

void permuation(char* a, int k ,int m) {
	int i,j;
	if(k==m){
		for(int i=0;i<=m;i++){
			cout<<a[i];
		}
		cout<<endl;
	}
	else {
		for(int j=k;j<=m;j++) {
			swap(a[j],a[k]);
			permuation(a,k+1,m);
			swap(a[j],a[k]);
		}
	}
}

int main(int argc, char* argv[]) {

	char ch[N];
	int n;
	cin>>ch;
	n = strlen(ch)-1;
	permuation(ch,0,n);
	return 0;
}

