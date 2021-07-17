

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {

	int len =10;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v.resize(len);

	cout<<"the first value of V i "<<endl;
	for(int i=0;i<v.size();i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;

	cout<<"the second value of V i "<<endl;

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	for(int i=0;i<v2.size();i++) {
		cout<<v2[i]<<" ";
	}

	return 0;
}

