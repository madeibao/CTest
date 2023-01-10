


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
	string temp;

	void track(const string& temp, int index) {
		if(index == temp.size()) {
			result.push_back(temp);
			return;
		}

		int digit = temp[index]-'0';
		string letters = map[digit];
		for(int i=0;i<letters.size();i++) {
			s.push_back(letters[i]);
			track(temp,index+1);
			s.pop_back();
		}

	}

	vector<string> letterCombinations(string digits) {

		result.clear();
		temp.clear();

		if(digits.size()==0) {
			return result;
		}

		track(digits,0);
		return result;
	}


}
int main(int argc, char** argv) {

	return 0;
}