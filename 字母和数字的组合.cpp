
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
	const string map[10] = {
  		"", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
	};

public:
	vector<string> result;
	string s;

   void track(const string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';        // 将index指向的数字转为int
        string letters = map[digit];      // 取数字对应的字符集
        for (int i = 0; i < letters.size(); i++) {
            s.push_back(letters[i]);            // 处理
            track(digits, index + 1);    // 递归，注意index+1，一下层要处理下一个数字了
            s.pop_back();                       // 回溯
        }
    }
	vector<string> letterCombinations(string digits) {

		result.clear();
		s.clear();

		if(digits.size()==0) {
			return result;
		}

		track(digits,0);
		return result;
	}
};


int main(int argc, char*argv[]) {

	Solution s;
	string str = "23";
	vector<string> res;
	res = s.letterCombinations(str);

    for(string temp:res) {
        cout<<temp<<endl;
    }
	return 0;
}
