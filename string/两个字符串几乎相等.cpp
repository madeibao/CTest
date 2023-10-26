



#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {

        vector<int> numa(26);
        vector<int> numb(26);

        for(int i=0;i<word1.size();i++) {
            numa[word1[i]-'a']++;
        }
        for(int i=0;i<word2.size();i++) {
            numb[word2[i]-'a']++;
        }

                // 遍历 26 个字母的相对位置，如果两边出现的次数的绝对值大于3，返回 false
        for (int i = 0; i < 26; i++)
        {
            if (abs(numa[i] - numb[i]) > 3)
            {
                return false;
            }
        }

        // 最后没有返回 false 则返回 true
        return true;

    }
};

int main() {
    string word1 = "abcdeef", word2 = "abaaacc";

    Solution s2;
    cout<<s2.checkAlmostEquivalent(word1,word2)<<endl;
    return 0;
}
