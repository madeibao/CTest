
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> res;

        res = split(s);
        set<char> set2(pattern.begin(),pattern.end());
        set<string> set3;
        for(auto i:res) {
            set3.insert(i);
        }

        if(pattern.size()!=res.size()) {
            return false;
        }
        if(set2.size()!=set3.size()) {
            return false;
        }
        
        unordered_map<char, string> map2;
        for(int i=0;i<pattern.size();i++) {
            map2[pattern[i]] = res[i];
        }   

        for(int i=0;i<pattern.size();i++) {
            if(map2[pattern[i]]!=res[i]) {
                return false;
            }
        }

        return true;
    }

    vector<string> split(string s) {
        int len = s.length();
        int i(0);
        string ans= "", temp;
        vector<string> res;

        while(i<len) {
            temp = "";
            while(i<len&&s[i]==' ') {i++;}
            while(i<len&&s[i]!=' ') {
                temp += s[i++];
            }
            res.push_back(temp);
        }

        return res;
    }
};


int main(int argc, char** argv) {

    string   pattern = "abba", s = "dog cat cat dog";
    Solution s2;
    cout<<s2.wordPattern(pattern,s)<<endl;
    return 0;
}