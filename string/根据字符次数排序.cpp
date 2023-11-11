

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto &c:s) mp[c]++;
        sort(s.begin(),s.end(),[&](const char &a,const char &b){
            return mp[a]==mp[b] ? a>b : mp[a]>mp[b];
        });
        return s;
    }
};

int main() {

    string s = "tree";
    Solution s2;
    cout<<s2.frequencySort(s)<<endl;
    return 0;
}
