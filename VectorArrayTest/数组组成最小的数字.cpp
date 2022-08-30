
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {

public:
	string minNum(vector<int>& nums) {
		if(nums.size()==0) return nullptr;

		vector<string> res;
		for(int i=0; i<nums.size();i++) {
			res.push_back(nums[i]);
		}

		sort(res.begin(), res.end(), [](string o1, string o2){return o1+o2<o2+o1;});
		string res2 = nullptr;
		for(int i=0; i<res.size();i++) {
			res2+= res[i];
		}
		return res2;
	}
};

int main(int argc, char* argv[]) {

	vector<int> res {10, 2};
	Solution s;
	cout<<s.minNum(res)<<endl;
	return 0;
}