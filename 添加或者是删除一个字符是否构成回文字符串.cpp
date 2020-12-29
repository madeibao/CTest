
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	bool isPalindrome(const string &s, int low, int high) {

		while (low <high) {
			if(s[low++]!=s[high--]) {
				return false;
			}
		}
		return true;
	}
	bool validPalindrome(string s) {

		int low =0, high = s.size()-1;
		while(low<high) {

			if(s[low]==s[high]) {
				++low;
				--high;
			}
			else {
				return isPalindrome(s, low, high-1)&&isPalindrome(s,low+1, high);
			}
		}
		return true;
	}
};


int main(int argc, char* argv[]) {

	string s ="abca";
	Solution s2;
	cout<<s2.validPalindrome(s);
	return 0;
}
