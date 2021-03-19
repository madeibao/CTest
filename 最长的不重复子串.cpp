


#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        unsigned int res = 0;


        for(unsigned int i = 0, j = 0;j < s.size(); j ++ )
        {
            hash[s[j]] ++;
            while(hash[s[j]] > 1) {

            	// 左面的指针来进行移动，向右面的指针来移动。
                hash[s[i++]]--;
            }
            res = max(res, j - i + 1);
        }
        
        return res;
    }
};


int main(int argc, char **argv) {

	string str2= "abcabcbb";
	Solution s;
	cout<<s.lengthOfLongestSubstring(str2)<<endl;
	return 0;
}
