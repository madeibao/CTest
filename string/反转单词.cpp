
#include<iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len = s.length(), i = 0;
        string ans = "", tmp;
        while(i < len) {
            tmp = "";
            while(i < len && s[i] == ' ') i++;
            while(i < len && s[i] != ' ') tmp += s[i++];
            if(tmp != ""){
                ans = tmp + " " + ans;
            }
        }
        return ans.substr(0, ans.length()-1);
    }
};

int main() {

    string s = "the sky is blue";
    string res;
    Solution s2;
    res = s2.reverseWords(s);
    cout<<res<<endl;
    return 0;
}