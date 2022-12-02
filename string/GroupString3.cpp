

// 字母的异位词分组

#include "iostream"
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	unordered_map<string, vector<string>> map2;
        vector<vector<string>> str2;
    	if(strs.size()==0) {
    		return str2;
    	}

    	for(string str:strs) {
    		string temp = str;
    		sort(temp.begin(), temp.end());
    		map2[temp].push_back(str);
    	}

        for(auto j:map2) {
            str2.push_back(j.second);
        }
        return str2;
    }
};

int main(int argc, char* argv[]) {
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution s;
	vector<vector<string>> groupAnagrams;
	groupAnagrams = s.groupAnagrams(strs);
	for(auto i:groupAnagrams) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
}
