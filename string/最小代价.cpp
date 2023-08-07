


#include<bits/stdc++.h>
#include<iostream>

using namespace std;

const int N = 1e5+7;
int ch1[100],ch2[100], res = 0;


int main(int argc, char* argv[]) {


	scanf("%s%s",str1,str2);
	int n = strlen(str1);
	for(int i=0; i<n;i++) {
		ch1[str1[i]-'a']++;
		ch2[str1[i]-'a']++;
	}


	for(int i=0;i<n;i++) {
		if(str1[i]!=str2[i]){
			puts("-1");
			return 0;
		}
	}

	for(int i=0;i<n;i++) {
		if(str1[i]==str2[res]) {
			res++;
		}
	}
	printf("%d\n",n-res);
	cout<<"hello"<<endl;
	return 0;
}


