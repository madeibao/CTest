



#include "iostream"
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:

	vector<vector<string> > groupAnagrams(vector<string> & strs) {
		vector<vector<string>> res;

		unordered_map<string,vector<string> > map2;

		for(auto str : strs) {

			// 将数组中的值赋予一个临时变量
			string t = str;
			sort(t.begin(), t.end());
			map2[t].push_back(str);
		}


		for(auto j:map2) {
			res.push_back(j.second);
		}

		return res;

	}
};


int main(int argc, char **argv) {

	vector<string> res = {"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution s;
	vector<vector<string>> res2;
	res2 = s.groupAnagrams(res);
	for(auto i:res2) {
		for(auto j:i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
