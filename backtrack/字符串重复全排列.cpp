


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string path = "";
    vector<string> result;
    vector<bool> used;

    void backtracking(string s){
        if(path.size() == s.size()){
            result.emplace_back(path);
        }
        for(int i = 0;i < s.size();++i){
            if(i > 0 && s[i] == s[i-1] && used[i-1] == false){
                continue;
            }
            //自身去重，用过了不能再用了
            if(used[i] == false){
                used[i] = true;
                path.push_back(s[i]);
                backtracking(s);
                used[i] = false;
                path.pop_back();
            }
        }
    }

    vector<string> permutation(string S) {
        int n = S.size();
        used.resize(n,false);
        //树层去重要排序，要让重复的字母在字符串中挨在一起
        sort(S.begin(),S.end());
        backtracking(S);
        return result;
    }
};
int main() {

    string str = "qqe";
    Solution s2;
    vector<string> res;
    res = s2.permutation(str);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}
