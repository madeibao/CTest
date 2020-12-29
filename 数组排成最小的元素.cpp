
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
	string minNum(vector<int>& nums) {

		// C++11提出的匿名函数，简洁的解法。
		auto compare = [](string sa, string sb) {return sa+sb<sb+sa;};

		vector<string> temp;
		for(int n:numbers) {
			temp.push_back(to_string(n));
		}

		sort(temp.begin(), temp.end(), compare);
		string ans = "";
		for(string s:temp) {
			ans+= s;
		}
		return ans;
	}
};

int main(int argc, char* argv[]) {

	vector<int> nums ={2,32,14,23,34};
	Solution s;
	cout<<s.minNum(nums)<<endl;
	return 0;
}