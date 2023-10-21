
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {

        int index = -1;

        for(int i=0;i<word.size();i++) {
            if(word[i]==ch) {
                index = i;
                break;
            }
        }
        string str2 = word;
        string temp = str2.substr(0,index+1);

//        cout<<"-----"<<temp<<endl;
        reverse(temp.begin(),temp.end());

        string res = "";
        res+=temp;
        string temp2 = word.substr(index+1,word.size());

        res+=temp2;

        return res;
    }
};

int main() {

    string word = "abcdefd";
    char ch = 'd';
    Solution s2;
    cout<<s2.reversePrefix(word,ch)<<endl;
    return 0;
}

