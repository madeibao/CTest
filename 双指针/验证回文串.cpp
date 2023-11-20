

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

	    transform(s.begin(), s.end(), s.begin(), ::tolower);

        int i= 0, j =s.size()-1;

        while(i<j) {
            if(isLegal(s[i])&&isLegal(s[j])) {
                if(s[i]!=s[j]) {
                    return false;
                }
                i++;
                j--;
            }
            if(!isLegal(s[i])) {
                i++;
            }
            if(!isLegal(s[j])) {
                j--;
            }
        }

        return true;

    }

    static bool isLegal(char c) {
        return isalnum(c);
    }
};


int main() {

    string s = "A man, a plan, a canal: Panama";
    Solution s2;
    cout<<s2.isPalindrome(s)<<endl;

    return 0;
}
