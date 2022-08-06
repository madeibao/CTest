

// // /我们定义，在以下情况时，单词的大写用法是正确的：

// 全部字母都是大写，比如 "USA" 。
// 单词中所有字母都不是大写，比如 "leetcode" 。
// 如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
// 给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/detect-capital
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        int len = (int)word.length();
        for(int i = 0; i < len; ++i){
            if( word[i] >= 'A' && word[i] <= 'Z')cnt++;
        }
        if(cnt == 0 ||(cnt == 1 && word[0]<='Z') || cnt == len) return true;
        else return false;
    }
};

int main(int argc, char** argv) {

	string str ="USA";
	Solution s;
	cout<<s.detectCapitalUse(str)<<endl;
	return 0;
}
