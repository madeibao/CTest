

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(0 == s.size() && 0 == t.size()) {
            return true;
        }

        for(int index = 0; index <= s.size() - 1; index++) {
            if (s.find(s[index]) != t.find(t[index])) {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char* argv[]) {

	const char str2[] = "abb";
	const char str3[] = "cdd";
	Solution s;
	cout<<s.isIsomorphic(str2, str3)<<endl;
	return 0;
}