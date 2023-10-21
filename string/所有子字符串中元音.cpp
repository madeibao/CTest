



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0, n = word.size();
        for(int i = 0; i < n; ++i)
        {
            if(word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
            {
                ans += (i+1)*(n-i);
            }
        }
        return ans;
    }
};


int main() {

    string str = "aba";
    Solution s2;
    cout<<s2.countVowels(str)<<endl;
    return 0;
}
