
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
	string minNum(vector<int>& nums) {

		// C++11提出的匿名函数，简洁的解法。
		// auto compare = [](string sa, string sb) {return sa+sb<sb+sa;};
		auto cmp = [](const string a, const string b) {return a+b<b+a;};

		vector<string> temp;
		for(int n:nums) {
			temp.push_back(to_string(n));
		}

		sort(temp.begin(), temp.end(), cmp);
		string ans = "";
		for(string s:temp) {
			ans+= s;
		}
		return ans;
	}
};

int main(int argc, char* argv[]) {

	vector<int> nums ={10, 2, 12};
	Solution s;
	cout<<s.minNum(nums)<<endl;
	return 0;
}
