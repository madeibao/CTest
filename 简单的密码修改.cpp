

#include<bits/stdc++.h>
#include<iostream>

using namespace std; 


const string str1= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz"; 
const string str2= "bcdefghijklmnopqrstuvwxyza22233344455566677778889999";

char ecchange(char c) {
	for(int i=0; i<str1.size();i++) {
		if(str1[i]==c) {
			return str2[i];
		}
	}
	return a;
}

int main(int argc, char* argv[]) {

	string data;
	while(getline(cin, data)) {
		for(unsigned int i = 0; i <data.size(); i++) {
			data[i] = ecchange(data[i]);
		}
		cout<<data<<endl;
	}

	return 0;
}