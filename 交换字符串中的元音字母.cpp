

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string v = "aeiouAEIOU";
        int i = -1,j = s.size();
        while(i<j) {
            while(i<j && v.find(s[++i])==v.npos);
            while(i<j && v.find(s[--j])==v.npos);
            swap(s[i],s[j]);
        }
        return s;
    }
};


int main(int argc, char *argv[]) {

	string s2 = "hello";
	Solution s;
	cout<<s.reverseVowels(s2);
	return 0;
}