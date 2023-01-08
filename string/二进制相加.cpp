

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1;
        while(i >= 0 || j >= 0 || carry) {
            if(i >= 0) carry += a[i--] - '0';
            if(j >= 0) carry += b[j--] - '0';
            ans = to_string(carry % 2) + ans;
            carry /= 2;
        }
        return ans;
    }
};


int main(int argc, char* argv[]) {

	string stra ="11";
	string strb = "1";

	Solution s;
	cout<<s.addBinary(stra,strb)<<endl;

	return 0;

}
