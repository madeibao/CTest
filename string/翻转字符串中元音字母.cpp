
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        auto isVowel = [vowels = "aeiouAEIOU"s](char ch) {
            return vowels.find(ch) != string::npos;
        };

        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < n && !isVowel(s[i])) {
                ++i;
            }
            while (j > 0 && !isVowel(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};


int main(int argc, char* argv[]) {

	string str ="hello";
	Solution s;
	cout<<s.reverseVowels(str)<<endl;

	return 0;
}









在这里的目的是因为捕获里c++会自动推导变量类型，会把"aeiouAEIOU"推导成const char *const类型
但其实我们需要的是string类型，其实这里""s就是转成string类型等效于vowels = std::string("aeiouAEIOU")。