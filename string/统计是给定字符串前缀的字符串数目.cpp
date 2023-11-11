
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int index=0;
        for(int i=0;i<words.size();i++) {
            if(s.find(words[i],0)==0){
                index++;
            }
        }

        return index;
    }
};

int main(int argc, char* argv[]) {

	vector<string> words = {"a","b","c","ab","bc","abc"};
	string s = "abc";
	Solution s2;
	cout<<s2.countPrefixes(words,s)<<endl;
	return 0;
}