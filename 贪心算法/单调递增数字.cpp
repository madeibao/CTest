
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int res;
        string strnum = to_string(n);
        int len = strnum.size();
        int flag;

        for(int i = len - 1; i >= 1; i--)
        {
            if(strnum[i - 1] > strnum[i]) {
                flag = i;
                strnum[i - 1]--;
            }
        }
        for(int i = flag; i < len; i++)
        {
            strnum[i] = '9';
        }
        
        res = stoi(strnum);

        return res;
    }
};

int main() {

    Solution s2;
    int n = 1234;
    cout<<s2.monotoneIncreasingDigits(n)<<endl;
    return 0;
}