
#include<iostream>
#include<bits/stdc++.h>

using namespace std; //

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(int n : nums)
            strs.push_back(to_string(n));   //将int数组转换为string数组
        sort(strs.begin(), strs.end(), [](string &s1, string &s2){return s1+s2 < s2+s1;});  //按规则排序

        for(string s : strs)
            res += s;        //连接结果字符串

        return res;
    }
};



int main(int argc, char ** argv) {

	vector<int> nums {10,2};
	Solution s;
	cout<<s.minNumber(nums);
	return 0;
}