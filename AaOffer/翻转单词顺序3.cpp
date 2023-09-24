
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if(str == "")return "";
        stack<char> stacks;
        string res;
        int end = str.size() - 1;
        for(;end>=0;end--)
        {
            stacks.push(str[end]);
            if(str[end] == ' ' || end == 0)
            {
                if(end == 0)
                    stacks.push(' ');
                while(!stacks.empty())
                {
                    res.push_back(stacks.top());
                    stacks.pop();
                }
            }
        }
        res.erase(res.begin());
        return res;
    }
};

int main(int argc, char** argv) {   
    string str = "the sky is blue";
    Solution s2;
    string res;
    res = s2.reverseWords(str);
    cout<<res<<endl;

    return 0;
}