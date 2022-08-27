


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        string str="";
        for(int i =0;i<s.size();i++)  {
            if(isChar(s[i])) {
                str+=s[i];
            }
        }

        if(str == string(str.rbegin(), str.rend())) {
            return true;
        }
        return false; 

    }

    bool isChar(char c) {
        return (c>='a' && c<='z') || (c>='0'&& c<='9');
    }
};

int main(int argc, char* argv[]) {
	string str = "A man, a plan, a canal: Panama";

	Solution s;
	cout<<s.isPalindrome(str)<<endl;

	return 0;
}