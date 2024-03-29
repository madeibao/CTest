

// 中心扩展算法
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() < 1) {
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++) {
			int len1 = expandAroundCenter(s, i, i);//一个元素为中心
			int len2 = expandAroundCenter(s, i, i + 1);//两个元素为中心
			int len = max(len1, len2);
			if (len > end - start) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{// 计算以left和right为中心的回文串长度
			L--;
			R++;
		}
		return R - L - 1;
	}
};

int main(int argc, char** argv) {


	Solution s;
	string str2 = "babad";
	cout<<s.longestPalindrome(str2)<<endl;
	return 0;
}
