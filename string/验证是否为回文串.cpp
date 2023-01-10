
/**
 *  
    验证数字是否为回文字符串形式。

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public: 
   bool isPalindrome(string s) {

       int i=0;
       int j=s.size()-1;
       while (i<j) {

            while (i<j&&(!isdigit(s[i]))&&(!isalpha(s[i])) ) {
                i++;
            }
            while(i<j&&(!isdigit(s[j]))&&(!isalpha(s[j])) ) {
                j--;
            }

            if(tolower(s[i])!=tolower(s[j])) {
                return false;
            }
            ++i;
            --j;
     
        }
        return true;
    }
};


int main(int argc, char* argv[])  {
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    cout<<s.isPalindrome(str)<<endl;
    return 0;
}

