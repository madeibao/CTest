

#include "iostream"
#include "bits/stdc++.h"

using namespace std; 


void removeExtraSpaces(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' ') {   //遇到非空格处理
            	 //如果不是第一个位置，给单词间添加空格
                if (slow > 0)   {
                    s[slow++] = ' ';
                }
                //将单词读完整
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow); //slow的大小为去除多余空格之后的大小
}

int main( ) {

	string str = "   I am a boy ";
    removeExtraSpaces(str);
	cout<<str<<endl;
	return 0;
}