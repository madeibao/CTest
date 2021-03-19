

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
string longestCommonPrefix(vector<string>& strs) {
        // write code here
        if(!strs.size()) {
            return "";
        }
        string temp = strs[0];
        for(int i=1;i<strs.size();i++) {
            temp = common(temp, strs[i]);
            if(!temp.size()) {
                break;
            }
        }
        return temp;
    }

    string common(const string a, const string b) {
        int lena = a.size();
        int lenb = b.size();
        int len = min(lena, lenb);
        int i =0;
        while(i<len) {
            if(a[i]==b[i]) {
                i++;
            }
            else {
                break;
            }
        }
        return a.substr(0, i);
    }
};

int main() {
    vector<string> res {"abca","abc","abca","abc","abcc"};
    Solution s;
    cout<<s.longestCommonPrefix(res)<<endl;
    return 0;
}
