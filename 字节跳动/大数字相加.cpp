



#include "iostream"
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int carry = 0;
        int N1 = num1.size();
        int N2 = num2.size();
        int i = N1 - 1;
        int j = N2 - 1;
        while (i >= 0 || j >= 0) {
            int val1 = i >= 0 ? num1[i--] - '0' : 0;
            int val2 = j >= 0 ? num2[j--] - '0' : 0;
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            res += digit + '0';
        }

        
        if (carry == 1) {
            res += '1';
        }

        reverse(res.begin(), res.end());

        return res;
    }
};


int main(int argc, char **argv) { 


	Solution s; 
	cout<<s.addStrings("1","99");
	return 0;

}

