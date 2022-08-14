
#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i +=k*2) {
        reverse(s.begin() + i, s.begin() + min(i + k, n));    
        }
        return s;
    }
};


int main(int argc, char** argv) {

	string str = "abcdefg";
	int k = 2;

	Solution s;
	cout<<s.reverseStr(str,k)<<endl;
	return 0;
}


