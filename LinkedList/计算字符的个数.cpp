

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	char* ch[10000];
	char c;
	int len = 0;
	cin>>ch;
	for(int i=0;i<strlen(ch);i++) {
		if(ch[i]==c||ch[i]==c-32||ch[i]==c+32) {
			len +=1;
		}
	}
	cout<<len;
	return 0;
}