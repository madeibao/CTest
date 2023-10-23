



#include "iostream"
#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    string replaceSpace(string s) {
  		string ans;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                ans += "%20";
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {

	Solution s2;
	string str = "We are happy.";

	cout<<s2.replaceSpace(str);
	return 0;
}