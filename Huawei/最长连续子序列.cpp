

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {


	int sum;
	string s;
	vector<int> v;

	cin>>s>>sum;
	string temp;
	for(int i=0;i<s.size();i++) {
		if(s[i]!=',') {
			temp+=s[i];
		}
		else {
			v.push_back(stoi(temp));
			temp = "";
		}
	}
	v.push_back(stoi(temp));


	for(int i=v.size();i>=1;i--) {
		for(int j=0;j<(v.size()-i+1);j++) {
			int t = 0;
			int k = 0;
			while(k<i) {
				t+=v[j+k];
				k++;
			}
			if(t==sum) {
				cout<<k<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
