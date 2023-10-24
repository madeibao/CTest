


#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        int index=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ') index++;
            if(index==k) break;
            ans+=s[i];
        }
        return ans;
    }
};

int main() {

    string s = "Hello how are you Contestant";
    int k =4;
    Solution s2;
    cout<<s2.truncateSentence(s,k)<<endl;
    return 0;
}
