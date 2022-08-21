

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int zero = 0,one = 0;
        for(char c : s) {
            if(c == '1') one ++;
        }

        int res = INT_MIN;
        for(int i=0;i<s.length()-1;i++) {
            if(s[i] == '0') {
                zero ++;
            }else if(s[i] == '1') {
                one --;
            }
            res = max(res,one+zero);
        }
        return res;
    }
};

int main(int argc, char** argv) {

	string str = "011101";
	Solution s;
	cout <<s.maxScore(str)<<endl;
	return 0;
}
