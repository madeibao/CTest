
#include<iostream>

using namespace std;

class Solution {
public:
    bool point(string x) {
        int l = 0 , r = x.size() - 1;
        while(l < r){
            if(x[l++] != x[r--]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        string temp;
        int l = 0 , r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                string x = s.substr(l + 1 , r - l), y = s.substr(l , r - l); // x 是删除了 l 位置的值 ， y 是删除了 r 位置的值
                if(point(x) || point(y)){
                    return true; // 分别删除两边字符，判断是否可行
                }
                else {
                    return false;
                }
            }
            l++; 
            r--;
        }
        return true;
    }
};

int main() {
    string str = "aba";
    Solution s2;
    cout<<s2.validPalindrome(str)<<endl;

    return 0;
}
