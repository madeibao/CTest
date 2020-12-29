

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> m;
		for(string s:strs) {
			string t = s;
			sort(t.begin(), t.end());
			m[t].push_back(s);
		}

		for(auto n:m) {
			res.push_back(n.second);
		}
		return res;
	}
};

int main(int argc, char* argv[]) {

	vector<string> res{"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> temp;
	Solution s;
	temp = s.groupAnagrams(res);
	for(auto it:temp) {
		for(auto j:it) {
			cout<<j<<" ";
		}
		cout<<endl;
	}

	return 0;
}
