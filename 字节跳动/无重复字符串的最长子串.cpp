


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int start=0;//储存字符串的起始下标
        int max=0;//记录字符串最长长度
        for(int i=0;i<s.size();i++)
        {
            for(int j=start;j<i;j++)//遍历子字符串中有没有重复字符
            {
                if(s[j]==s[i])
                {
                    start=j+1;
                    //保证了前一个数和最新数之间的子字符串最多只有两个相同字母，所以可以跳出循环
                    break;
                }
            }
            //每次循环更新无重复字符串最大长度
            if(i-start+1>max) {
            	max = i-start+1;
            }
        }
        return max;
    }
};


int main(int argc, char* argv[]) {

	string str2= "abcabcbb";
	Solution s;
	cout<<s.lengthOfLongestSubstring(str2)<<endl;
	return 0;
}
