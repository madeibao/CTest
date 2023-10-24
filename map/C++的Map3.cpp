
/**
	按照 key 排序
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct rule {
	bool operator()(const string a, const string b) {
		return a > b;
	}
};


int main(int argc, char** argv) {

	map<string, int, rule> ma;
	ma["aaa"] = 2;
	ma["bbb"] = 3;
	ma["ccc"] = 4;

	map<string, int, rule>::iterator it;
	for(it = ma.begin(); it != ma.end(); ++it) {
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}