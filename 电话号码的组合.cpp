
#include<iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return res;
        backTrace(digits, 0);
        return res;
    }

// 私有属性，智能类的内部使用。
private:
    unordered_map<char, string> phoneString {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
    string s;
    vector<string> res;

    // 回溯算法
    void backTrace(string digits, int index) {
        // 结束条件
        if(digits.size() == index) {
            res.push_back(s);
        }
        // for 每个位置当下选择的字母 in 每个位置可选择的字母集合 
        for (unsigned int i = 0; i < phoneString[digits[index]].size(); ++i) {
            // 第index个位置选择的字母
            s += phoneString[digits[index]][i];
            // 为下个位置选择字母
            backTrace(digits, index+1);
            // 撤销上次位置的字母选择，因为那个位置要重新选字母
            s.pop_back();
        }
    }
};


int main(int argc, char** argv) {

	vector<string> strs;
	Solution s;
	string str2= "23";
	strs = s.letterCombinations(str2);

	for(string temp:strs) {
		cout<<temp<<" ";
	}

	return 0;
}
