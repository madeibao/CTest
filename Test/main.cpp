


//-----------------------------------------------------------------------------
// 第一个唯一字符


#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = max(s.size(),t.size());
        char res= ' ';
            for(int i=0;i<t.size();i++) {
                if(t.find(t[i])!=nullptr&&s.find(t[i])!=nullptr ) {
                    continue;
                }
                else {
                    res = t[i];
                }
            }
                    return res;
        }


};

int main() {

	Solution s2;
    string s = "abcd", t = "abcde";

    cout<<s2.findTheDifference(s,t)<<endl;
	return 0;

}

