

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

char firstChar(string s) {

    vector<char> ch(26, 0);
    for(char c:s) {
        ch[c-'a'] +=1;
    }

    for(char c:s) {
        if(ch[c-'a'] ==1) {
            return c;
        }
    }

    return ' ';

}

int main(int argc, char** argv) {

    string str2 ="leetcode";
    cout<<firstChar(str2)<<endl;
    return 0;
}