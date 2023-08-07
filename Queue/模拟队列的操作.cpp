

#include<iostream>
#include<bits/stdc++.h>

using namespace std; 

int main(int argc, char* argv[]) {
	int n,x;
	cin >> n;
	queue<int> q;
	string str;
	while (n--) {
		cin >> str;
		if(str=="add") {
			cin>>x;
			q.push(x)
		}

		else if(str=="poll") {
			q.pop();
		}
		else {
			cout<<q.front()<<endl;
		}
	}
	return 0;
}