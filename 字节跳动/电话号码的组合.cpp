



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {


public:
    vector<string> backTrace(string str) {
        if(str.size()==0) {
            return res;
        }
        dfs(str,0);
        return res;
    }
private:
    string s;
    vector<string> res;
    unordered_map<char, string> map2 {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };

    void dfs(string digits, int index) {
        if(digits.size()==index) {
            res.push_back(s);
        }
        for(unsigned int i=0;i<map2[digits[index]].size();i++) {
            s+= map2[digits[index]][i];
            dfs(digits, index+1);
            s.pop_back();
        }
    }
};

int main(int argc, char** argv) {

	vector<string> strs;
	Solution s;

	strs = s.backTrace("23");
	for(auto temp:strs) {
		cout<<temp<<" ";
	}

	return 0;
}

