
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {

        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < n && !isVowel(s[i])) {
                ++i;
            }
            while (j > 0 && !isVowel(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }

    bool isVowel(char c) {
        string str = "aeiouAEIOU";
        if(str.find(c)!=string::npos ) {
            return true;
        }
        return false;
    }

};


int main(int argc, char* argv[]) {

	string str ="hello";
	Solution s;
	cout<<s.reverseVowels(str)<<endl;

	return 0;
}






