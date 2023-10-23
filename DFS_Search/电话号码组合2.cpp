




#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    char str[9][5]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string s) {
       if(s=="") return res;
        dfs(s, 0, "");
        return res;
    }   
    void dfs(string &s, int u, string tmp){
        if(u == s.size()){
            res.push_back(tmp);
            return;
        }
        for(int j = 0; str[s[u]-'2'][j]; j++){
            dfs(s,u+1, tmp+str[s[u]-'2'][j]);
        }
        
    }
};

int main() {

	string digits = "2";
	vector<string> res;
	Solution s2;
	res = s2.letterCombinations(digits);
	for(auto i:res) {
		cout<<i<<" ";
	}
	return 0;
}
