
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
    	int i = 0;
    	int j = s.size()-1;

    	while(i<j) {
    		if(!isalpha(s[i])) {
    			i++;
    		}
    		else if(!isalpha(s[j])) {
    			j--;
    		}
    		else if(isalpha(s[i])&&isalpha(s[j])) {
    			swap(s[i++],s[j--]);
    		}
    	}

    	return s;
    }
};


int main() {

	string s = "a-bC-dEf-ghIj";
	Solution s2;
	cout<<s2.reverseOnlyLetters(s)<<endl;

}
