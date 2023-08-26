

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

    	unordered_set<string> set2 = {wordDict.begin(), wordDict.end()};

    	vector<bool> dp(s.size()+1);
    	dp[0] = true;

    	for(int i=1;i<=s.size();i++) {
    		for(int j=0;j<i;j++) {
    			if(set2.find(s.substr(i,i-j))==set2.end()&&dp[j]) {
    				dp[i] = true;
    				break;
    			}
    		}
    	}
    	return dp[s.size()];
    }
};


int main(int argc, char** argv) {

	string s = "applepenapple";
	vector<string> wordDict = {"apple", "pen"};
	Solution s2;
	cout<<s2.wordBreak(s,wordDict)<<endl;
	return 0;
}
