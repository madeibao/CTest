
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> set2;

        for(auto i:s) {
            if(set2.find(i)==set2.end()) {
                set2.insert(i);
            }
            else {
                return i;
            }
        }

        return 0;
    }
};

int main() {

    string s = "abccbaacz";
    Solution s2;
    cout<<s2.repeatedCharacter(s)<<endl;
    return 0;
}
