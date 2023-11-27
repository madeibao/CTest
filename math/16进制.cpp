

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toHex(int num) {

        if(num==0) {
            return "0";
        }

        string res = "";
        string hex[16] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        unsigned int num2 = num;

        while(num2!=0) {
            res.insert(0,hex[num2%16]);
            num2 = num2/16;
        }
        return res;
    }
};


int main(int argc, char** argv) {

    Solution s2;
    cout<<s2.toHex(26);
    return 0;
}
