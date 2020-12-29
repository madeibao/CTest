
/**
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            char t = s[left];
            s[left++] = s[right];
            s[right--] = t;
        }
    }
};

int main(){
    vector<char> ch = {'h','e','l','l','0'};
    Solution s;
    s.reverseString(ch);
    for(int i=0;i<ch.size();i++) {
        cout<<ch[i]<<" ";
    }
    return 0;
}
*/






