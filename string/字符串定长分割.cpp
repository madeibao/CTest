


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string& str,int n) {
	vector<string> res;

	while (str.size() > n) {
		res.push_back(str.substr(0,n));
		str= str.substr(n);
	}
	res.push_back(str);
	return res;
}

int main(int argc, char* argv[]) {

	string str = "abcabcabcabcabcabcabcab";
	vector<string> res;
	res = split(str,3);
	for(string str:res) {
		cout<<str<<endl;
	}
	return 0;
}
