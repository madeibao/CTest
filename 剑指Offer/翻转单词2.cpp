


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "",temp;
        stringstream ss(s);
        while(ss >> temp) {
            res = temp + " " + res;
        }
        res.pop_back();
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