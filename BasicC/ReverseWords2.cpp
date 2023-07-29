

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverse(string s) {
        int len = s.length();
        int i(0);
        string ans= "", temp;

        while(i<len) {
            temp = "";
            while(i<len&&s[i]==' ') {i++;}
            while(i<len&&s[i]!=' ') {
                temp += s[i++];
            }
            if(temp!="") {
                ans = temp +" "+ans;
            }
        }
        return ans.substr(0, ans.length()-1);
    }
};

int main() {

    string s = "the sky is blue";
    string res;
    Solution s2;
    res =s2.reverse(s);
    cout<<res<<endl;
    return 0;
}
