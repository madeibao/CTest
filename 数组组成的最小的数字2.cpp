

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	string minNum(vector<int>& nums) {
		if(nums.size()<=0) {
			return "";
		}

		sort(nums.begin(), nums.end(),cmp);

		string res="";

		for(int i:nums){
			res+=to_string(i);
		}
		return res;
	}

	static bool cmp(int a,int b){
		string A="";
		string B="";

		A+=to_string(a);
		A+=to_string(b);

		B+=to_string(b);
		B+=to_string(a);

		return A<B;
		
	}


}

int main() {

	vector<int> nums= {1,2,1};
	Solution s;
	cout<<s.minNum(nums)<<endl;

	return 0;
}