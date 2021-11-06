

// 最后一个单词的长度值。
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }

        int N = s.size();
        int end = N - 1;

        // 去掉单词的右面的空格。
        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        if (end < 0) {
            return 0;
        }

        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }


        // 根据差值来计算出结果
        return end - start;
    }
};


int main(int argc, char* argv[]) {


    string s = "   fly me   to   the moon  ";
    Solution s2;
    cout<<s2.lengthOfLastWord(s)<<endl;
    return 0;
}
