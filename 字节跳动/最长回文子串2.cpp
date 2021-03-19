
// 最长的回文子串长度。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void help(const string &s, int left, int right, int& start, int& maxlen){    //中心扩散
        while(left >= 0 && right < s.size())
        {
            if(s[left] != s[right]) {
                break;
            }

            --left;
            ++right;
        }

        if(right - left - 1 > maxlen )   //退出循环时，串的区间实际上是[left+1,right-1]
        {                                //区间长度，为(right - 1) - (left + 1) + 1 =  right -left - 1
            start = left + 1;
            // maxlen = right -left - 1;
            maxlen = right -(left+1);
        }
    }

    // 返回区间的长度值。

    string longestPalindrome(string s) {
        int start = 0, maxlen = 0;
        for(int i = 0; i < s.size(); ++i) {
            help(s,i,i,start,maxlen);
            help(s,i,i+1,start,maxlen);
        }
        return s.substr(start,maxlen);
    }

};


int main(int argc, char **argv) {

	string str = "babad";
	Solution s;
	cout<<s.longestPalindrome(str)<<endl;
	return 0;
}
