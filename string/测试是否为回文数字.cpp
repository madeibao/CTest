

#include<bits/stdc++.h>
#include<iostream>
using namespace std; 

class Solution {
public:
	bool isHui(int x) {
		vector<int> a,b;
		while(x) {
			a.push_back(x%10);
			x /= 10;
		}
		b=a;
		reverse(a.begin(),a.end());
		if(a==b) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main(int argc, char* argv[]) {
	Solution s;
	cout << s.isHui(121);
	return 0;
}




#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
	public:
	bool isHui(int x) {
		vector<int> a, b;
		while (x) {
			a.push_back(x%10);
			x /=10;
		}
		b =a;
		reverse(a.begin(), a.end());
		if(a==b) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main(int argc, char *argv[]) {

	int x = 121;
	Solution s;
	cout<<s.isHui(x)<<endl;
	return 0; /**/
}