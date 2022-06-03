
#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map1; 
        for(string &str:strs) {
            string key = str;
            sort(key.begin(), key.end());
            map1[key].push_back(str);
        }

        
        vector<vector<string>> ans;
        for(auto it=map1.begin(); it != map1.end(); ++it){
            ans.push_back(it->second);
        }
        return ans;
    }
};



int main(int argc, char** argv) {

	vector<string> strs ={"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution s;

	vector<vector<string>> res;

	res = s.groupAnagrams(strs);

	for(auto i:res) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}