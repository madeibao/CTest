



#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin()); t.erase(t.end() - 1); // 掐头去尾
        if (t.find(s) != std::string::npos) return true; // r
        return false;
    }
};


int main(int argc,char** argv) {

	string str = "abab";
	Solution s2;
	cout<<s2.

	return 0;
}