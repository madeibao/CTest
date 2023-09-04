
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        string s = to_string(x);
        return s == string(s.rbegin(), s.rend());
    }
};

int main(int argc, char **argv) {

	int num = 121;
	Solution s2;
	cout<<s2.isPalindrome(num)<<endl;

	return 0;
}