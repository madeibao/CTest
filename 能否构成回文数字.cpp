
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hash;
        for(auto ch: s) hash[ch]++;
        int num = 0;
        for(auto val: hash)
            if(val.second % 2) num++;

        if(num<=1) {
            return true;
        }
        else {
            return false;
        }
    }
};


int main() {
    string s = "moom";
    Solution ss;
    cout<<ss.canPermutePalindrome(s)<<endl;
    return 0;
}


