
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {

        int cnt = 0;
		// 滑动窗口长度
		int windowSize = 3;
		int len = s.length();
		// 顺序遍历字符串
		for (int i = 0; i <= len - windowSize; i++)
		{
			// 子字符串要连续，且各字符不相等
			if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2])
			{
				cnt++;
			}
		}
		return cnt;
    }
};


int main() {
    string s = "xyzzaz";
    Solution s2;
    cout<<s2.countGoodSubstrings(s)<<endl;
    return 0;
}






