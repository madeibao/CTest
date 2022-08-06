
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generate(int n) {

        vector<string> strs;
        if(n<=0) {return strs;}

        helper(strs, "", n, n);
        return strs;
    }

    // 括号的生成算法。
    void helper(vector<string>& strs, string temp, int left, int right) {

        if(left<0||right<0||left>right) {
            return;
        }

        if(left==0&&right==0) {
            strs.push_back(temp);
        }

        helper(strs,temp+"(",left-1, right);
        helper(strs,temp+")",left, right-1);
    }


};

int main(int argc, char* argv[])  {

    int n =3;
    vector<string> res;
    Solution s;
    res = s.generate(n);
    for(string s:res) {
        cout<<s<<"  "<<endl;
    }
    return 0;
}

