


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.size()==0&&t.size()==0) {
            return true;
        }
        for(unsigned int i=0;i<=s.size()-1;i++) {
            if(s.find(s[i])!=t.find(t[i])) {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char* argv[]) {

	string s ="abb";
	string t ="cdd";

	Solution s2;
	cout<<s2.isIsomorphic(s,t)<<endl;

	return 0;
}
