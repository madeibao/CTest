

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	void reverse(string &s, int start, int end) {
		int i = start;
		int j = end;

		for(int i= start,j=end; i<j; i++,j--) {
			swap(s[i],s[j]);
		}
	}

	// 去除字符串中的多余空格
	void removeExtraSpaces(string &s ) {

		int slow = 0;
		for(int fast = 0; fast<s.size(); fast++) {
			if(s[fast] != ' ') { 	//遇到非空格处理
				if(slow > 0) { 		//如果不是第一个位置，给单词间添加空格
					s[slow++] = ' ';
				}
				while(fast<s.size() && s[fast]!=' ') {
					s[slow++] = s[fast++];
				}
			}
		}
	}

	string reverseWords(string s) {
        removeExtraSpaces(s);   //去除多余空格
        reverse(s, 0, s.size() - 1);    //反转整个s
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，进行单词反转
                reverse(s, start, i - 1);
                start = i + 1;  //更新下一个单词的开始下标
            }
        }
        return s;
    }
};

int main(int argc, char** argv) {
    string str = "the sky is blue";
    Solution s2;
    string res;
    res = s2.reverseWords(str);
    cout<<res<<endl;

    return 0;
}
