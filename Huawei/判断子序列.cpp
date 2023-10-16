

#include<iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        for (int i = 0, j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                // 若已经遍历完 s ，则提前返回 true
                if (++i == s.size())
                    return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    string s = "abc", t = "ahbgdc";
    Solution s2;
    cout<<s2.isSubsequence(s,t)<<endl;

	return 0;
}
