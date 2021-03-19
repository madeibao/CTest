
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool palindrome(string s) {
		int i =0, j = s.size()-1;
		while(i<j) {
			if(s[i]!=s[j]) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
};



int main(int argc, char*argv[] ){


	string str ="aba";
	Solution s;
	cout<<s.palindrome(str)<<endl;

	return 0;
}
