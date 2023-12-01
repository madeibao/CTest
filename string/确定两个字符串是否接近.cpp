




#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int num1[26], num2[26];
    vector<int>q1,q2;
    bool closeStrings(string word1, string word2)
    {
        if(word1.length()!=word2.length())return false;
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));

        for(int i=0;i<word1.length();i++)
        {
            num1[word1[i]-'a'] ++;
        }
        
        for(int i=0;i<26;i++)
        {
            q1.push_back(num1[i]);
        }

        memset(num2,0,sizeof(num2));

        for(int i=0;i<word2.length();i++)
        {
            num2[word2[i]-'a'] ++;
        }
        for(int i=0;i<26;i++)
        {
            q2.push_back(num2[i]);
        }

        sort(q1.begin(),q1.end());
        sort(q2.begin(),q2.end());

        for(int i=0;i<q1.size();i++)
        {
            if(q1[i]!=q2[i])return false;
        }
        //确保字符类型相同
        for(int i=0;i<26;i++)
        {
            if(num1[i]>0&&num2[i]==0||num1[i]==0&&num2[i]>0)return false;
        }
        return true;
    }
};


int main(int argc, char** argv) {

    string word1 = "cabbba", word2 = "abbccc";
    Solution s2;
    cout<<s2.closeStrings(word1,word2)<<endl;

    return 0;
}
