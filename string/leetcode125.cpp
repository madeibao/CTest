

// 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

// 说明：本题中，我们将空字符串定义为有效的回文串。

// 示例 1:

// 输入: "A man, a plan, a canal: Panama"
// 输出: true
// 解释："amanaplanacanalpanama" 是回文串

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/valid-palindrome
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        string str="";
        for(int i =0;i<s.size();i++)  {
            if(isChar(s[i])) {
                str+=s[i];
            }
        }

        if(str == string(str.rbegin(), str.rend())) {
            return true;
        }
        return false;

    }

    bool isChar(char c) {
        return (c>='a' && c<='z') || (c>='0'&& c<='9');
    }
};


int main(int argc, char* argv[]) {

	string str="A man, a plan, a canal: Panama";
	Solution s;
	cout << s.isPalindrome(str)<<endl;
	return 0;

}
