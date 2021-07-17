
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    string addStrings(string num1, string num2) {
        string res = "";

        int i1 = num1.length() - 1, i2 = num2.length() - 1;
        int carry = 0;
        while (i1 >= 0 || i2 >= 0) {
            int x = i1 >= 0 ? num1[i1] - '0' : 0;
            int y = i2 >= 0 ? num2[i2] - '0' : 0;

            int sum = x + y + carry;
            res.push_back('0' + sum % 2);
            carry = sum / 2;

            i1--;
            i2--;
        }
        if (carry != 0) res.push_back('0' + carry);

        // 最后将结果翻转
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char* argv[]) {

	Solution s;
	string str="001";
	string str2= "110";
	string res;
	res = s.addStrings(str, str2);
	cout<<res<<endl;

	return 0;
}
