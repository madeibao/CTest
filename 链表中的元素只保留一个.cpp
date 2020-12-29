

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

	int n,k;
	while(~(scanf("%d %d",&n,&k))) {
		int val;

		for(int i=1;i<=n;i++) {
			scanf("%d",&val);
			if(i==k) {
				continue;
			}
			printf("%d ",val);
		}
		cout<<endl;
	}
	return 0;
}
