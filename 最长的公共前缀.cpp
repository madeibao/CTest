

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r = strs.size() ? strs[0] : "";
        for(auto s: strs) {
            while(s.substr(0, r.size()) != r) {

                // 不断的截取数字减去,右面减去1
                r = r.substr(0, r.size() - 1);
                if(r == "") return r;
            }
        }
        return r;
    }
};


int main(int argc, char* argv[])  {

    string[] strs = {"fly", "flower", "flame"};
    Solution s;
    cout <<s.longestCommonPrefix(strs) << endl;
    return 0;
}



