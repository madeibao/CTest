


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> mp, mp2;
        for (char c : s) mp[c]++;
        for (char c : target) mp2[c]++;

        int ans = 1e9;
        
        for (char c : target) {
            ans = min(ans, mp[c] / mp2[c]);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {

	Solution s2;
    string s = "codecodecodecode", target = "codecode";
    cout<<s2.rearrangeCharacters(s,target)<<endl;

	return 0;

}
