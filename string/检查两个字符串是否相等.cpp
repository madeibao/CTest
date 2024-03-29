
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        for(auto s : word1) {
            str1 += s;
        }
        for(auto s : word2) {
            str2 += s;
        }
        return str1 == str2 ? true : false;
    }
};

int main() {

	vector<string> word1 = {"ab", "c"}, word2 = {"a", "bc"};
	Solution solution;
	cout<<solution.arrayStringsAreEqual(word1,word2)<<endl;

	return 0;
}
